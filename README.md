# SudokuGame

Mini project for Advance Programming class, developed using C and GTK+ for GUI.

## Prerequisites

1. It is recommended to use MinGW Compiler. Other compilers might work, but are not officially supported.
2. GTK+3.0 is needed for developing GUI interface. For further information about download and installation you can visit [GTK](https://www.gtk.org/download/index.php) official page.
3. A proper workstation, recommended 64-bit architecture.

## Get the source code

Use `git clone` command in terminal or use `git pull` to get the latest source code

## Compiling

1. Using MinGW compiler</br>
    ```
    gcc main.c -o main (`pkg-config --cflags --libs gtk+-3.0`) // remove the brackets
    ```

   alternatively, you can use `pkg-config` to get and copy all linker and compiler flags. Use those as options when run `gcc` command
    ```
    pkg-config --cflags --libs gtk+-3.0
    ```


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details


