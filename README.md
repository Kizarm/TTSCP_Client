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
