# Slon2k19
# 2. Чёрный ящик.

  > f(x) = -1 + 1 / (x + 1) 
  
  т.к.  
  f(-1) неопределено  
  x->inf => f(x)->-1  
  x->-inf => f(x)->-1  
  x->-1(+) => f(x)->inf  
  x->-1(-) => f(x)->-inf  
  f(1) = -0.5  
  f(-3) = -1.5  
  
# 3. Раскраска кубика
  > 18
  
  Если не перекрашивать красную грань:  
    - Грань, противоположную красной, можно раскрашивать или нет - это умножает количество раскрасок, независимых от неё, на 2. Если раскрасить одну, три, четыре грани, то возможных раскрасок, не переходящих друг в друга поворотом, будет по одной. Если раскрасить две - их будет две. Итого (1 + 1 + 1 + 2) * 2 = 10  
  
  Если перекрасить красную грань в зелёный:  
    - Если раскрасить ещё только одну, две, три - уникальных раскрасок будет две, если четыре, пять - одна. Итого (2 + 2 + 2 + 1 + 1) = 8  
    
    10 + 8 = 18
  
# 4. Загадочный текст

  > если вы читаете это, то вы, вероятно, догадались, что это шифровка. трудно ли было её разгадать? сделали ли вы это вручную или с помощью программы? короткие слова, такие как предлоги и союзы, наверняка облегчили вам задачу. так или иначе, поздравляем! в качестве ответа нужно сдать слова \"седиментация по фэншую\" или текст целиком. но берегитесь! если вы сдадите неверный ответ, то получить полный балл вы уже не сможете.  
  
  `python3 sub.py`
  
# 6. Слонение
  > 10
  
  x, y - целые  
  7x - 3y = 40  
  x + y -> min  
  
  y = (7x - 40) / 3  
  y >= 0 => x >= 7  
  
  x + y = (10x - 40) / 3 = min при x = 7 => y = 3 => x + y = 10  

# 9. Дождь  
  ```
  g++ rain.cpp -o rain
  ./rain
  ```
  
# 11. Белый ящик
  `document.cookie = "session_id=" + "a".repeat(32)`  
  InversionSpaces
  
# 12. Разрезание
  > tuk.jpg
  
# 14. Гистограмма
  ```
  g++ hist.cpp -o hist
  ./hist
  ```
