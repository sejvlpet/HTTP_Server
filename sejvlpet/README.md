# HTTP SERVER


## Originální zadání
HTTP server

Úkolem je naprogramovat jednoduchý HTTP server s podporou různých generátorů obsahu. Generátor obsahu musí podporovat:

1. výpis obsahu adresáře
2. konkrétní html stránka (statický obsah)
3. externí skript nebo program

Server musí implementovat:

1. načítání konfiguračního souboru
2. parametry naslouchání na síti (IP adresa, port)
3. omezení na práci s konkrétním adresářem
4. log přenosů (kam se má ukládat, v jakém formátu, jak má vypadat hlavička každého záznamu, ...)
5. vypnutí serveru na (konfigurovatelné) URL adrese

HTTP server může umět obsloužit více domén nebo poskytovat virtuální filesystém (mapování virtuálních URL na fyzické cesty na disku)

Volitelně: Podpora HTTPS (openssl), vícevláknové obsloužení klientů

Kde lze využít polymorfismus? (doporučené)

* Druh souboru: adresář, HTML soubor, obrázek, skript, nepodporovaný formát, ...
* Logování: na konzoli, do souboru, do databáze, ...
* Styl logování: jednoduchá hlavička, kompletní požadavek (např. pouze pro chybové stavy), statistika přístupů, ...

## Specifikované zadání
* Server bude pracovat ve více vláknech
* V rámci generování obsahu pomocí externích skriptů budou implementovány unit testy posílající
requesty na server a porovnávající obdržené odpovědi s očekávanými

## Polymorfismus
* Logy - každá údalost která se loguje si vytvoří instanci příslušného potomka
třídy Log, ta je pak předáná (resp. pointer/reference na ni) až loggeru, která z virtuální metodu ToString získá řetězec 
a zaloguje jej
* Logger - server má členskou proměnou která je typu std::unique_ptr na Logger a v rámci setupu
serveru je naplněna dítětem zvoleným v konfiguraci (FileLogger nebo ConsoleLogger). Při logování se pak
volají přetížené metody těchto tříd
* Response - Třída controller rozhodne jaká response je třeba zapsat podle toho si vytvoří potomka třídy
Response, na které se pak zavolá virtuální metoda WriteOut vypisující příslušnou odpověd

## Poznámka
* Budete-li chtít mít možnost spustit unit testy, využije příkaz `$ make tests`, který zkompiluje testy
a spustitelné soubory uloží do router/tests/bin, spustit je můžete z prohlížeče
    * V rámci unit testů je bug - server test obvykle "nezaregistruje ihned" a odpoví na něj až s jiným
    voláním
* BUG - protože implementaci stále obsahuje bugy, tak jsem ty o kterých vím označil v takto v komentářích
* ASK_X - Věci které bych ještě chtěl projít, čím menší X, tím menší priorita
* Do implemntaci by měla ještě přijít práce s thready pomocí thread poolu a možnost vlastní konfigurace
podoby logů, také dojde pravděpodobně k refactoringu celkové struktury
