# Лабораторная работа №1. Сортировка массивов.

## Реализация алгоритмов.

### Реализация Selection Sort

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L11-L18

### Реализация Insertion Sort

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L20-L32

### Реализация Merge Sort

Для сортировки слиянием было реализовано два варианта алгоритма. 
Один отличается от другого оптимизацией аллокаций памяти: у первого буффер для соединения двух сортированных подмассивов выделяется каждый раз заново, 
а у второго - буффер был создан заранее и переиспользуется всеми частями алгоритма.

#### Реализация Merge Sort без оптимизации аллокаций

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L34-L86 

#### Реализация Merge Sort с оптимизацией аллокаций

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L88-L141

### Реализация Heap Sort

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L143-L205

### Реализация Quick Sort

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L207-L249

### Реализация Bucket Sort

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/sort.hpp#L251-L275

## Анализ результатов

Полную табличку с результатами можно найти [здесь](https://github.com/unterumarmung/algo-class/blob/main/sort/results/output.csv).

Первый столбец задаёт имя алгоритма сортировки. 
Первая строка - количество сортируемых элементов. 
На пересечении: время выполнения алгоритма на массиве с заданным количеством элементов в наносекундах.

Результаты получены на процессоре i5-7300HQ с помощью компилятора g++-10 в Release сборке.

Для графического представления результата был написан Python3 скрипт:

https://github.com/unterumarmung/algo-class/blob/ba590e5988e25903b27f9c3e13c91bd14dce3eec/sort/analyze_results.py#L1-L12

Полученный график:

![Анализ результатов запуска алгоритмов сортировки](https://github.com/unterumarmung/algo-class/blob/main/sort/results/plot.png)

Как видно из графика, оптимизированный Merge Sort действительно быстрее своей неоптимизированной версии. 
