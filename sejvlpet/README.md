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
* Program lze spustit se vstupním parametrem - konfiguračním souborem. Pokud program tento soubor dostane, podle definovaných pravidel se z něj pokusí vyčíst a nastavit si dané hodnoty, pokud nedostane, pokračuje s defaultními. Pro ukázku konfiguračního souboru vizte examples/config.txt.
* Po získání konfiguračních hodnot se pomocí nich server pokusí připravit na poslouchání na síti. V případě selhání se vypíše log chyby (z důvodu možnosti chyby v rámci nastavování logů jako takových se ze začátku logguje pouze s defaultním nastavením). Pokud vše vyjde jak má, server začne poslouchat na dané adrese a portu.
* V reakci na request předá server socket Controlleru - ten zajistí parsování requestu a se sparsovaným requestem vytvoří Workera kterého předá do thread poolu.
* Server implementuje a pro práci ve více vláknech využívá thread pool. Díky tomu je teda schopen obsluhovat více požadavků najednou. Počet vláken je nastavitelný v konfiguračním souboru stejně jako velikost fronty pro požadavky čekající na vyřízení.
* Když dojde Worker v thread poolu na řadu, rozhodne na základě requestu jak se zachovat - vytvoří příslušnou response a zajistí její vrácení.
* Během běhu serveru probíhá logování.
* K funcionalitě jsou implementovány unit testy - spustíte je pomocí make runTests (testy nejsou úplně standalone - například pro test spustitelného souboru je třeba daný soubor mít, konkrétně zkompilovat examples/tests/helloWorld.cpp jako examples/tests/helloWorld, pro test nepřístupného adresáře je třeba takový adresář vytvořit (vizte testInvalidPermissions.cpp))

## Polymorfismus
* Logy - každá udalost která se loguje si vytvoří instanci příslušného potomka
třídy Log, ta je pak předáná (resp. reference na ni) až loggeru, která z virtuální metody ToString získá řetězec 
a zaloguje jej)
* Logger - server má členskou proměnou která je typu std::unique_ptr na Logger a v rámci setupu
serveru je naplněna dítětem zvoleným v konfiguraci (FileLogger nebo ConsoleLogger). Při logování se pak
volají přetížené metody těchto tříd
* Response - Instance Workera  rozhodne jaká response je třeba zapsat podle toho si vytvoří potomka třídy
Response, na které se pak zavolá virtuální metoda WriteOut vypisující příslušnou odpověd
