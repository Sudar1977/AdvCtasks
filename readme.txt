1. Нужно ли переносить строки в тестах для улучшения читаемости теста:
1.1 01-A7 - Задачи 001, 002, 003 - много править;
1.2 02-А0, A1 блоки памяти;
1.3 05-А1 две строки.
Оставлены как есть
2. Пустые dat - 01 - А7 - Задачи 004, 005, 007.
Удалены
3. Нужно ли делать только функции - 07-A0
Пока как есть
4. Исправить ссылку на .bin файлы
Завсисит от сервера. Выложить на сервер файлы 
\Sol\08\input01.dat 
\Sol\08\output01.dat
\Sol\08\input02.dat 
\Sol\08\output01.dat
5. Добвить header 
enable_text_form
source_header = "header.с"
[problem]
id = 1
super = "Generic"
short_name = "F1"
long_name = "Сортировка по возрастанию"
type = "standard"
standard_checker = "cmp_int_seq"
enable_text_form
source_header = "header.с"
source_footer = "footer.с"
6. Переименовать папки и задачи с А на другие буквы B,C,D,E