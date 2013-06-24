#ひきたしソルバー
一部で盛り上がっているひきたしのソルバー。
前回の数独ソルバーはOCamlだったけど、今回はC++。
あと、コンパイラはのりでclang使ってみた。

##入力
標準入力によって与える。
はじめに、使える数字の数を入力。
その後はスペース区切りで使える数字を入力。
最後につくるべき数字を入力

つくれなかったら無言で終了する。
つくれたら、その式を表示。
ケースによっては結構時間かかるかも。

使える数字の数は15個までに限定。
また、計算の途中で20000を超える分子・分母が出てきた場合、そのようなケースは破棄されてしまう。

例によって作りが甘いので、インプットに変なものを入れるとバグると思う。

一応、いくつかサンプルインプットを用意したので参考にしてください。

実行例：`./product < sample`

##簡単なアルゴリズム解説
使った数についての集合をビット列で表現し、それぞれについて、
つくれる数をキーとしたとその数をつくるための式をmapで保持。
あとは、ひたすらDFS。

結構めちゃくちゃなコードになっている。

## バグ
これだと探索範囲が狭いことに気がついてしまった。
割と致命的な気がするんだけど、これでも結構なケース通ってしまって意外。
そのうちなおす。
