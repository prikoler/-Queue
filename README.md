# Задачи на 2 лабораторные работы
## 1. Необходимо построить линейный односвязный список вида "очередь". Каждый узел списка описывает телефонный звонок и имеет информационные поля:
  - Номер телефона-источника (11 знаков);
  - Номер телефона-приёмника (11 знаков);
  - Продолжительность разговора в минутах (целое число).

Информация для построения списка вводится с клавиатуры. Признак окончания - "0". Для построенного списка необходимо:
  - Вывести информацию о звонке с максимальной длительностью разговора;
  - Очистить память после использования списка.
  
## 2. Для списка из "Работы №2" необходимо выполнить следующие преобразования:
  - Вывести на экран телефон с максимальным количеством исходящих звонков;
  - Заменить узлы, соответствующие звонкам с продолжительностью больше 5-ти на необходимое количество узлов с длительностью разговора <=5 так, чтобы исходная длительность равнялась сумме длительностей в заменяющих узлах. Длительность в замещающем узле выбирать, как максимально возможную, например, если в узле было 12, то будет 5, 5 и 2.
