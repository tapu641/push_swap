#!/bin/bash

PASS=0
FAIL=0
BIN=./push_swap
CHECKER=./checker_linux

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
GRAY='\033[0;90m'
RESET='\033[0m'

check()
{
	local desc="$1"
	local expect_stdout="$2"
	local expect_stderr="$3"
	local expect_exit="$4"
	shift 4
	local actual_stdout
	local actual_stderr
	local actual_exit
	local tmpout
	local tmperr

	echo -e "${GRAY}  $ $*${RESET}"
	tmpout=$(mktemp)
	tmperr=$(mktemp)
	"$@" >"$tmpout" 2>"$tmperr"
	actual_exit=$?
	actual_stdout=$(cat "$tmpout")
	actual_stderr=$(cat "$tmperr")
	rm -f "$tmpout" "$tmperr"

	local ok=1
	if [ "$expect_exit" != "any" ] && [ "$actual_exit" != "$expect_exit" ]; then
		ok=0
	fi
	if [ "$expect_stdout" = "empty" ] && [ -n "$actual_stdout" ]; then
		ok=0
	fi
	if [ "$expect_stdout" = "nonempty" ] && [ -z "$actual_stdout" ]; then
		ok=0
	fi
	if [ "$expect_stderr" = "Error" ] && [ "$actual_stderr" != "Error" ]; then
		ok=0
	fi
	if [ "$expect_stderr" = "empty" ] && [ -n "$actual_stderr" ]; then
		ok=0
	fi

	echo -e "       stdout : '${actual_stdout}'"
	echo -e "       stderr : '${actual_stderr}'"
	if [ "$ok" = "1" ]; then
		echo -e "${GREEN}[PASS]${RESET} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "       exit   : ${actual_exit}  (expected ${expect_exit})"
		echo -e "${RED}[FAIL]${RESET} $desc"
		FAIL=$((FAIL + 1))
	fi
}

check_sorted()
{
	local desc="$1"
	shift

	echo -e "${GRAY}  $ $BIN $*${RESET}"

	if [ ! -x "$CHECKER" ]; then
		echo -e "${RED}[SKIP]${RESET} $desc (checker_linux が見つかりません)"
		return
	fi

	local ops
	local tmperr
	tmperr=$(mktemp)
	ops=$($BIN "$@" 2>"$tmperr")
	local stderr_out
	stderr_out=$(cat "$tmperr")
	rm -f "$tmperr"

	if [ -n "$stderr_out" ]; then
		echo -e "${RED}[FAIL]${RESET} $desc (stderr: $stderr_out)"
		FAIL=$((FAIL + 1))
		return
	fi

	if [ -z "$ops" ]; then
		echo -e "${RED}[FAIL]${RESET} $desc (stdout が空: 操作が出力されていない)"
		FAIL=$((FAIL + 1))
		return
	fi

	local ops_count
	ops_count=$(echo "$ops" | wc -l | tr -d ' ')
	echo -e "       stdout(${ops_count}行): $(echo "$ops" | tr '\n' ' ')"

	local checker_result
	checker_result=$(echo "$ops" | $CHECKER "$@" 2>/dev/null)
	echo -e "${GRAY}  $ echo \"{ops}\" | $CHECKER $* → $checker_result${RESET}"

	if [ "$checker_result" = "OK" ]; then
		echo -e "${GREEN}[PASS]${RESET} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "${RED}[FAIL]${RESET} $desc"
		FAIL=$((FAIL + 1))
	fi
}

check_strategy()
{
	local desc="$1"
	local flag="$2"
	shift 2

	echo -e "${GRAY}  $ $BIN $flag $*${RESET}"

	if [ ! -x "$CHECKER" ]; then
		echo -e "${RED}[SKIP]${RESET} $desc (checker_linux が見つかりません)"
		return
	fi

	local ops
	local tmperr
	tmperr=$(mktemp)
	ops=$($BIN "$flag" "$@" 2>"$tmperr")
	local stderr_out
	stderr_out=$(cat "$tmperr")
	rm -f "$tmperr"

	if [ -n "$stderr_out" ]; then
		echo -e "${RED}[FAIL]${RESET} $desc (stderr: $stderr_out)"
		FAIL=$((FAIL + 1))
		return
	fi

	if [ -z "$ops" ]; then
		echo -e "${RED}[FAIL]${RESET} $desc (stdout が空)"
		FAIL=$((FAIL + 1))
		return
	fi

	local ops_count
	ops_count=$(echo "$ops" | wc -l | tr -d ' ')
	echo -e "       stdout(${ops_count}行): $(echo "$ops" | tr '\n' ' ')"

	local checker_result
	checker_result=$(echo "$ops" | $CHECKER "$@" 2>/dev/null)
	echo -e "${GRAY}  $ echo \"{ops}\" | $CHECKER $* → $checker_result${RESET}"

	if [ "$checker_result" = "OK" ]; then
		echo -e "${GREEN}[PASS]${RESET} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "${RED}[FAIL]${RESET} $desc"
		FAIL=$((FAIL + 1))
	fi
}

check_perf()
{
	local desc="$1"
	local limit_pass="$2"
	local limit_good="$3"
	local limit_excellent="$4"
	shift 4

	echo -e "${GRAY}  $ $BIN $* | wc -l${RESET}"

	if [ ! -x "$CHECKER" ]; then
		echo -e "${RED}[SKIP]${RESET} $desc (checker_linux が見つかりません)"
		return
	fi

	local ops tmperr
	tmperr=$(mktemp)
	ops=$($BIN "$@" 2>"$tmperr")
	local stderr_out
	stderr_out=$(cat "$tmperr")
	rm -f "$tmperr"

	if [ -n "$stderr_out" ]; then
		echo -e "${RED}[FAIL]${RESET} $desc (error: $stderr_out)"
		FAIL=$((FAIL + 1))
		return
	fi

	local ops_count
	ops_count=$(echo "$ops" | wc -l | tr -d ' ')

	local checker_result
	checker_result=$(echo "$ops" | $CHECKER "$@" 2>/dev/null)

	local grade
	if [ "$ops_count" -lt "$limit_excellent" ]; then
		grade="${GREEN}Excellent${RESET}"
	elif [ "$ops_count" -lt "$limit_good" ]; then
		grade="${CYAN}Good${RESET}"
	elif [ "$ops_count" -lt "$limit_pass" ]; then
		grade="${YELLOW}Pass${RESET}"
	else
		grade="${RED}FAIL (上限超過)${RESET}"
	fi

	echo -e "       ops数: ${ops_count}  checker: ${checker_result}  評価: $(echo -e $grade)"

	if [ "$checker_result" = "OK" ] && [ "$ops_count" -lt "$limit_pass" ]; then
		echo -e "${GREEN}[PASS]${RESET} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "${RED}[FAIL]${RESET} $desc (ops: ${ops_count} / 上限: ${limit_pass})"
		FAIL=$((FAIL + 1))
	fi
}

echo -e "${CYAN}========================================${RESET}"
echo -e "${CYAN}  push_swap unit tests${RESET}"
echo -e "${CYAN}========================================${RESET}"

# ============================================================
echo -e "\n${YELLOW}--- 引数なし / 少ない ---${RESET}"
# ============================================================
check "引数なし"         empty empty 0 $BIN
check "引数1つ (5)"      empty empty 0 $BIN 5
check "引数1つ (-3)"     empty empty 0 $BIN -3

# ============================================================
echo -e "\n${YELLOW}--- すでにソート済み ---${RESET}"
# ============================================================
check "2要素 昇順"        empty empty 0 $BIN 1 2
check "3要素 昇順"        empty empty 0 $BIN 1 2 3
check "5要素 昇順"        empty empty 0 $BIN 1 2 3 4 5
check "10要素 昇順"       empty empty 0 $BIN 1 2 3 4 5 6 7 8 9 10

# ============================================================
echo -e "\n${YELLOW}--- 数値以外の文字 ---${RESET}"
# ============================================================
check "アルファベット (a)"      empty Error 1 $BIN a
check "アルファベット混じり"    empty Error 1 $BIN 1 2 a
check "英数字混じり (1a)"       empty Error 1 $BIN 1a
check "記号 (#)"                empty Error 1 $BIN 1 '#' 3
check "小数点 (1.5)"            empty Error 1 $BIN 1.5
check "空文字列 (\"\")"         empty Error 1 $BIN ""

# ============================================================
echo -e "\n${YELLOW}--- int 境界値テスト ---${RESET}"
# ============================================================
check "INT_MAX     (2147483647)"  empty empty 0 $BIN 2147483647
check "INT_MAX + 1 (2147483648)"  empty Error 1 $BIN 2147483648
check "INT_MAX + 2 (2147483649)"  empty Error 1 $BIN 2147483649
check "INT_MIN     (-2147483648)" empty empty 0 $BIN -2147483648
check "INT_MIN - 1 (-2147483649)" empty Error 1 $BIN -2147483649
check "非常に大きい数"            empty Error 1 $BIN 99999999999

# ============================================================
echo -e "\n${YELLOW}--- 重複数値 ---${RESET}"
# ============================================================
check "重複 (1 1)"       empty Error 1 $BIN 1 1
check "重複 (1 2 1)"     empty Error 1 $BIN 1 2 1
check "重複 (3 3 3)"     empty Error 1 $BIN 3 3 3

# ============================================================
echo -e "\n${YELLOW}--- フラグ付きエラー (PDF p.16) ---${RESET}"
# ============================================================
check "--adaptive + 文字混じり"  empty Error 1 $BIN --adaptive 0 one 2 3
check "--simple + 重複"          empty Error 1 $BIN --simple 3 2 3

# ============================================================
echo -e "\n${YELLOW}--- ソート動作確認 (checker_linux) ---${RESET}"
# ============================================================
check_sorted "2要素 逆順"       2 1
check_sorted "3要素 逆順"       3 2 1
check_sorted "3要素 ランダム"   2 3 1
check_sorted "5要素 逆順"       5 4 3 2 1
check_sorted "5要素 ランダム"   3 1 5 2 4
check_sorted "10要素 ランダム"  7 3 9 1 5 8 2 6 4 10

# ============================================================
echo -e "\n${YELLOW}--- ストラテジーフラグ ---${RESET}"
# ============================================================
check_strategy "--simple   3要素"   --simple   3 2 1
check_strategy "--medium   3要素"   --medium   3 2 1
check_strategy "--complex  3要素"   --complex  3 2 1
check_strategy "--adaptive 3要素"   --adaptive 3 2 1
check_strategy "--simple   5要素"   --simple   5 4 3 2 1
check_strategy "--medium   5要素"   --medium   5 4 3 2 1
check_strategy "--complex  5要素"   --complex  5 4 3 2 1
check_strategy "--adaptive 5要素"   --adaptive 5 4 3 2 1
check_strategy "--complex  PDF例"   --complex  4 67 3 87 23

# ============================================================
echo -e "\n${YELLOW}--- --bench フラグ ---${RESET}"
# ============================================================
echo -e "${GRAY}  $ $BIN --bench 3 2 1${RESET}"
bench_stderr=$($BIN --bench 3 2 1 2>&1 >/dev/null)
bench_stdout=$($BIN --bench 3 2 1 2>/dev/null)
echo -e "       stdout : '$(echo "$bench_stdout" | tr '\n' ' ')'"
echo -e "       stderr : '$(echo "$bench_stderr" | tr '\n' ' ')'"
if echo "$bench_stderr" | grep -q "\[bench\]"; then
	echo -e "${GREEN}[PASS]${RESET} --bench: stderrに[bench]行が出力される"
	PASS=$((PASS + 1))
else
	echo -e "${RED}[FAIL]${RESET} --bench: stderrに[bench]行が出力されない"
	FAIL=$((FAIL + 1))
fi
if [ -n "$bench_stdout" ]; then
	echo -e "${GREEN}[PASS]${RESET} --bench: stdoutに操作が出力される"
	PASS=$((PASS + 1))
else
	echo -e "${RED}[FAIL]${RESET} --bench: stdoutに操作が出力されない"
	FAIL=$((FAIL + 1))
fi

# ============================================================
echo -e "\n${YELLOW}--- パフォーマンステスト (PDF VI.6) ---${RESET}"
# ============================================================
echo -e "${GRAY}  ※ 100要素: <2000=Pass / <1500=Good / <700=Excellent${RESET}"
echo -e "${GRAY}  ※ 500要素: <12000=Pass / <8000=Good / <5500=Excellent${RESET}"

ARGS100=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
check_perf "100要素 ランダム" 2000 1500 700 $ARGS100

ARGS500=$(shuf -i 1-50000 -n 500 | tr '\n' ' ')
check_perf "500要素 ランダム" 12000 8000 5500 $ARGS500

# ============================================================
echo -e "\n${CYAN}========================================${RESET}"
echo -e "  結果: ${GREEN}PASS ${PASS}${RESET} / ${RED}FAIL ${FAIL}${RESET}"
echo -e "${CYAN}========================================${RESET}"

[ $FAIL -eq 0 ] && exit 0 || exit 1
