# Лабораторная работа №2. Бинарные деревья поиска.

Реализация бинарного дерева поиска представлена в файле https://github.com/unterumarmung/algo-class/blob/0bdbf1c920a771ad2cb0ab2b16e18b2444c9ed85/bst/tree.hpp#L1-L104

Примеры нескольких запусков:

```
$ ./build/bst/bst
Generated random vector of 13 elements: 
[110, 77, 53, 237, 242, 34, 249, 2, 42, 245, 91, 123, 250]
Generated tree: 
2 34 42 53 77 91 110 123 237 242 245 249 250 
The tree contains all the values from the vector: true
```
```
$ ./build/bst/bst
Generated random vector of 93 elements: 
[201, 142, 170, 24, 5, 125, 203, 92, 76, 130, 122, 30, 183, 42, 132, 27, 90, 194, 12, 5, 183, 70, 120, 177, 148, 56, 108, 184, 58, 106, 145, 39, 38, 241, 150, 241, 111, 147, 185, 15, 22, 250, 155, 16, 110, 65, 239, 251, 139, 152, 223, 139, 66, 149, 183, 17, 27, 41, 215, 135, 93, 94, 37, 25, 231, 252, 249, 186, 249, 11, 124, 101, 71, 216, 218, 125, 176, 88, 248, 126, 45, 20, 48, 29, 27, 246, 178, 233, 55, 196, 187, 234, 131]
Generated tree: 
5 11 12 15 16 17 20 22 24 25 27 29 30 37 38 39 41 42 45 48 55 56 58 65 66 70 71 76 88 90 92 93 94 101 106 108 110 111 120 122 124 125 126 130 131 132 135 139 142 145 147 148 149 150 152 155 170 176 177 178 183 184 185 186 187 194 196 201 203 215 216 218 223 231 233 234 239 241 246 248 249 250 251 252 
The tree contains all the values from the vector: true
```
```
$ ./build/bst/bst
Generated random vector of 42 elements: 
[170, 82, 128, 152, 68, 221, 199, 137, 2, 147, 199, 226, 144, 251, 22, 30, 215, 28, 44, 171, 181, 95, 62, 22, 111, 30, 151, 41, 255, 3, 81, 152, 237, 250, 47, 53, 147, 253, 137, 13, 250, 154]
Generated tree: 
2 3 13 22 28 30 41 44 47 53 62 68 81 82 95 111 128 137 144 147 151 152 154 170 171 181 199 215 221 226 237 250 251 253 255 
The tree contains all the values from the vector: true
```