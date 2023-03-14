# TTSCP_Client

## Motivace

TTS vyvinutý AV ČR docela dobře mluví česky. Protože neexistuje
další údržba kódu, udělal jsem patch pro 64-bit Linux. Na 32-bit
malině chodí bez úprav, nicméně nejde zapnout optimalizaci kódu.
Aplikace je typu klient / server a je docela chytře vymyšlená,
i když kód je dost kryptický. Do serveru se neodvážím zasahovat,
ale klienta je možné napsat podle popisu protokolu celkem snadno.
Vyžaduje dvě TCP spojení, ale není v tom nic složitého a tak by
to snad mohlo běžet třeba i na ESP32.

## Popis

Klient v hlavním adresáři běží ve smyčce a vyslovuje text na serveru,
tak jako původní program say. V adreáři file je klient, který už
získává data ze serveru a zapisuje je do souboru wav (GSM komprese).
V adresáři alsa je klient, který opět získá data ze serveru a přehrává
je lokálně pomocí Linuxového systému alsa.
Celé je to psáno pro Linux tak, aby to bylo jednoduché a šlo to případně
přepsat pro jinou (např. embedded) platformu. Je v tom pár vychytávek,
které v popisu původního epos nejsou a dalo dost práce je najít.

## Kecal

Konečným cílem celého snažení bylo naučit samostatně mluvit nějaký malý jednočip.
Dostat do toho celý TTS systém je asi nemožné, ale pokud chcete jen
vyslovovat čísla a pár slov navíc aby to umělo něco jako mluvící voltmetr
nebo teploměr, lze to obejít. Prostě namluvíte jednotlivá slova (číslice),
zkoprimujete to do GSM komprese a takto to uložíte do flash jednočipu.
Vyzkoušeno na STM32F051 jako teploměr, výstup je realizován jako PWM
časovačem (i když to má k dispozici DAC, není použit, PWM lze jednodušeji
zesílit a na kvalitě to také neubere). Zabere to asi 50kB flash
a 3kB RAM, výkon je více než dostečný. A kvalita je úplně někde jinde
než byla u 8-bitových chrchlátek. Zde je to namluveno automaticky pomocí
epos, ale samozřejmě je možné použít lepšího mluvčího a sestříhat to ručně.
Je to ale zbytečné, kvalita epos je slušná a GSM komprese to spíš ještě
vylepší. Důležitá je dostatečná hlasitost. Poměrně zastaralá GSM komprese
byla zvolena protože je dostatečně efektivní a lze jí použít
i na hodně malém jednočipu. Je to prostě kompromis.
