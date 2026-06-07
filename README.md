*This project has been created as part of the 42 curriculum by sito.*

## Description/

### exit() vs return
* exit()はプログラム全体を即終了させる
* returnは今いる関数は抜けて、呼び出し元に戻る

#### exit()の仕様
* IBMから引用「プログラムを終了する前に、すべてのバッファーを削除し、すべてのオープン・ファイルをクローズします」とあり、実質的にリークは残らないが、明示的にfree()する。

## Instructions

## Resources/参考
[exit() プログラムの終了](https://www.ibm.com/docs/ja/i/7.4.0?topic=functions-exit-end-program)


