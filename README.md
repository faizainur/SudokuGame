# SudokuGame

Mini project for Advance Programming class, developed using C and GTK+ for GUI.

## Prerequisites
'''
!!! WARNING !!!
You can't compile and run the EXE files if you do not install all dependencies
'''
1. It is recommended to use MinGW Compiler. Other compilers might work, but are not officially supported.
2. GTK+3.0 is needed for developing GUI interface. For further information about download and installation you can visit [GTK](https://www.gtk.org/download/index.php) official page.
3. A windows based workstation, recommended 64-bit architecture.

## Installing dependencies
I recommend use [MSYS2](https://www.msys2.org/) to installing the dependencies needed. Run this command in [MSYS2](https://www.msys2.org/) terminal
```
pacman -Syu // updating package list
pacman -S <package-name> // remove the brackets
```
Any linux based installation instruction would run properly, since [MSYS2](https://www.msys2.org/) terminal very similar with linux terminal. You can look the package name [here](https://github.com/msys2/msys2/wiki/Packages).<br>
After installation, don't forget to set the `environment-path`.
```
NB : there are some libraries that you cannot install using MSYS2.
In that case, read the libraries documentation and follow the installation instruction
```
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


