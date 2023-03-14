/*OUTPUT_FORMAT (binary) možnosti zjistíme příkazem "objdump -i" (lze i ihex) */

ENTRY (sayed_texts)           /* odtud se začne (start po resetu)                     */
/* popis pamětí   */
MEMORY {
    ram (RWX) : ORIGIN = 0x00,    LENGTH = 0x40000
}
/* popis sekcí    */
SECTIONS {
  .fixed : {          /* výstupní sekce v rom - nazveme např. .fixed        */
    . = ALIGN (8);    /* zarovnání příští sekce na 4 byty (celkem zbytečné) */
    *(.data.rel.ro*)
    *(.rodata*)       /* .rodata* - stejně jako .text*, ale pro const proměnné (data) (-fdata-sections) */
    . = ALIGN (8);
    *(.text*)         /* gcc pojmenovává sekce s kódem jako .text, pokud je použito -ffunction-sections,
                         pak bude každá funkce v jiné sekci s názvy .text.jmeno_funkce, proto ta * na konci */
    . = ALIGN (8);
    *(.data*)         /* .data* - stejně jako .text*, ale pro proměnné (data inicializovaná)  */
    . = ALIGN (8);
    *(.bss*)          /* .bss*  - stejně jako .text*, ale pro proměnné (data inicializovaná na 0) */
    *(COMMON*)
    *(.note.*)
    relocate_end = .; /* konec dat v sekci .relocate - podle toho se např. nějak určí hodnota SP  */
    end = .;
  } > ram         /* tady je řečeno, že to má být v ram   */
  /DISCARD/ : {
    *(.rela*)
    *(.dynamic)
    *(.eh*)
    *(.debug*)
    *(.comment*)
    *(.interp)
    *(.dynsym)
    *(.dynstr)
    *(.hash)
    *(.gnu.hash)
    *(.header)
  } : phdr
}
