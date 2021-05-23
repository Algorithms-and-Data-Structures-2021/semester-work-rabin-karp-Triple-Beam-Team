# Алгоритм Рабина-Карпа by Triple Beam Team

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-rabin-karp-Triple-Beam-Team/actions/workflows/cmake.yml)

_Реализация Алгоритма Рабина-Карпа:_

- _Алгоритм ищет подстроку в тексте, используя хеширование._
- _Широко используется для поиска по тексту, проверки на плагиат (система Антиплагиат)_
- _Можно выполнять операции поиска в тексте по подстроке, вычисления хеша для следующей позиции, используя данные для нынешней._
- _Поиск подстроки выполняется за `O(n+m)` в лучшем и `O(n*m)` в худшем случаях, вычисление хеша - за `O(1)`_

## Команда "Triple Beam Team"

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Богдан        | 33.33     |  _travis fanboy_      |
| Орхан         | 33.33     |  _мини-маэстро_       |
| Тагир         | 33.34     |  _white chocolate_    |

**Девиз команды**
> _Without further interruption let's celebrate and find substirng_

## Структура проекта

**Проект состоит из следующих частей:**

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

**Рекомендуемые требования:**

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 8 ГБ.
5. Свободное дисковое пространство объемом ~ 2 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):
Пропишите в корне папки, в которую копируете репозиторий следующую команду

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-rabin-karp-Triple-Beam-Team.git
```

#### Генерация тестовых данных

Форат хранения данных - csv файлы со строками длины от 100 до 5000000 (с учетом того, что у вас минимум 8гб оперативной памяти).

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

1. Сначала вам нужно открыть файл **generate_csv_dataset.py** в папке dataset (с помощью любого блокнота).
2. В массиве **files** оставьте файлы с только теми числами, в размере которых вам нужно сгенерировать данные для проверки функций.
3. В массиве **folders** оставьте только те элементы вида **text_data/data_1/**, в которые вам нужно записать данные (data_n - это n-тая папка, в которой будут храниться .csv файлы, сгенерированные скриптом, если оставить несколько папок в массиве, то получится несколько разных наборов данных на одном количестве данных).
4. Запустите python скрипт:
```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_dataset.py
```

Тестовые данные представлены в CSV формате:

```csv
dlfjLIAIDJPOIFAJFPDikfjfhosijdffPDO:SIFJiojdfhshfuykglfidhgjjJFDSJFjGLKSHFGJKLHLlfgnjlgkfdjglfdgmfdmgmfdgnn
...
```

#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать из [Google Drive](https://drive.google.com/drive/folders/1_DmDNpdUIkO5mjc236s406SC8Z-zRt8Q) готовый набор тестовых данных.
**Напоминание.** Все десять папок с тестовыми данными должны находиться в папке "<Путь до репозитория>/dataset/text_data"

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `Search`                  | Поиск подстроки в тексте                | _время_         |

##### Примеры запуска

1. Открыть в IDE файл **search_for_substring.cpp**, находящийся в папке **benchmark**.
2. В массиве **folders** оставить только те папки /data_n/, которые вы скачали или в которые генерировали данные, аналогично с массивом files.
3. Запустить функцию main. Все замеры будут выводиться в консоль.

## Источники
- [Google Drive](https://drive.google.com/drive/folders/1_DmDNpdUIkO5mjc236s406SC8Z-zRt8Q)
- [Статья об алгоритме на Wikipedia](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)
- [Статья на GeeksForGeeks](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
- [Презентация с разбором примера работы алгоритма](https://www.slideshare.net/SohailAhmed255/rabin-karp-algorithm)
- [Подробное видео-объяснение](https://www.youtube.com/watch?v=qQ8vS2btsxI&ab_channel=AbdulBari)
- [Реализация алгоритма на С++](https://github.com/ashishmh/algorithms/blob/master/Rabin-karp.cpp)
