## ParserFromLog

## English

This is a simple program that will create a Batchfile(bat) file with a script to load Steam Workshop items using SteamCMD.

I use this program to download a folder/mod that I deleted. If I haven't updated them for a long time, there is a lot of work that I wanted to automate.

> Important: this program requires a SteamCMD log file (workshop_log.txt). It is from it that a list of modifications is formed that must be added to the Batchfile(bat) for their download.

### How to use.

This program needs several input parameters to work. Before use, you need to specify the SteamCMD log file (workshop_log.txt). The second parameter is the key string after which the modification id will be parsed. You can replace "294100" in the line " [AppID 294100] Download item " to change the game for which Batchfile(bat) will load. The third parameter is optional, it will change the name for Batchfile(bat).

### How it works

1. The program receives the text from the SteamCMD log file (workshop_log.txt) and immediately parses it.
2. The program generates a line of code for Batchfile(bat) and writes it.

## Українська

Це проста програма, яка створить Batchfile(bat) файл з скриптом зпрямований на загрузку предметів майстерні Steam за допомогою SteamCMD.

Я використовую цю програму для скачування папки/модифікації які я видалив. Якщо я довго не обновляв їх, то там появляється багато роботи, яку я захотів автоматизувати.

> Важливо: для цієї програми необхідно мати файл з логами SteamCMD(workshop_log.txt). Саме з нього утворюється список модифікацій, які потрібно добавити в Batchfile(bat) для їхнього завантаження.

### Як використовувати.

Цій програмі необхідні декілька вхідних параметрів для роботи. Перед використанням потрібно вказати фай логів SteamCMD(workshop_log.txt). Другий параметер це ключовий рядок після якого будуть парситись id модифікації. Можна замінити "294100" в рядку " [AppID 294100] Download item " для зміни гри для якї Batchfile(bat) буде заванажувати. Третій параметр не обов'язковий, він змінити назву для Batchfile(bat).

### Як працює

1. Програма отримує текст з файлу логів SteamCMD(workshop_log.txt) та одразу парсить його.
2. Програма формує рядок з кодом для Batchfile(bat) та записує її.