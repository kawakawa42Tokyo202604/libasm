# libasm

## English

A collection of x86-64 assembly functions for basic tasks such as counting and copying strings and reading or writing files. Assembly expresses operations close to the CPU's instructions.

The functions are packaged as `libasm.a` for use from C. For example, `ft_strlen("Hello")` returns `5`; the supplied demonstration compares results with the C standard library.

### Functions

| Function | Behavior |
| --- | --- |
| `ft_strlen` | Count the characters in a string |
| `ft_strcpy` | Copy a string |
| `ft_strcmp` | Compare strings |
| `ft_read` / `ft_write` | Read from or write to a file descriptor |
| `ft_strdup` | Duplicate a string |
| `ft_calloc` | Allocate zero-initialized memory |

### Build and run

Requires Linux x86-64 with glibc, NASM, a C compiler, and Make.

```sh
make            # Create libasm.a
cc -Wall -Wextra -Werror main.c libasm.a -o test_libasm
./test_libasm
```

The supplied `main.c` prints standard-library and custom-function results side by side. Run from the repository root because the demo also reads `main.c`.

### Implementation

- Assembles NASM ELF64 objects that can be linked into C programs.
- `ft_read` and `ft_write` use Linux system calls, set `errno` on failure, and return `-1`.

## 日本語

文字列の長さを数える、コピーする、ファイルを読み書きするといった基本処理を、x86-64アセンブリで実装した関数集です。アセンブリではCPUの命令に近い形で処理を記述します。

Cから呼び出せるライブラリファイル `libasm.a` にまとめています。例えば `ft_strlen("Hello")` は `5` を返し、付属のプログラムでC標準ライブラリと結果を比較できます。

### 関数

| 関数 | 動作 |
| --- | --- |
| `ft_strlen` | 文字列の長さを求める |
| `ft_strcpy` | 文字列をコピーする |
| `ft_strcmp` | 文字列を比較する |
| `ft_read` / `ft_write` | ファイルディスクリプタから読み込む・書き込む |
| `ft_strdup` | 文字列を複製する |
| `ft_calloc` | ゼロで初期化したメモリを確保する |

### ビルドと実行

Linux x86-64（glibc）・NASM・Cコンパイラ・Make が必要です。

```sh
make            # libasm.a を生成
cc -Wall -Wextra -Werror main.c libasm.a -o test_libasm
./test_libasm
```

付属の `main.c` は、標準ライブラリと自作関数の結果を並べて表示します。`main.c` を読み込む処理があるため、リポジトリ直下で実行します。

### 実装メモ

- NASM の ELF64 形式でアセンブルし、Cプログラムからリンクできます。
- `ft_read`・`ft_write` は Linux のシステムコールを使い、失敗時に `errno` を設定して `-1` を返します。
