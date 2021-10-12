#include "header.h"

void mx_printascii(char *segment){
    morse_table_t table[] = { {".-", "a"},
                              {"-...", "b"},
                              {"-.-.", "c"},
                              {"-..","d"},
                              {".","e"},
                              {"..-.","f"},
                              {"--.","g"},
                              {"....","h"},
                              {"..","i"},
                              {".---","j"},
                              {"-.-","k"},
                              {".-..","l"},
                              {"--","m"},
                              {"-.","n"},
                              {"---","o"},
                              {".--.","p"},
                              {"--.-","q"},
                              {".-.","r"},
                              {"...","s"},
                              {"-","t"},
                              {"..-","u"},
                              {"...-","v"},
                              {".--","w"},
                              {"-..-","x"},
                              {"-.--","y"},
                              {"--..","z"},
                              {".....","."}
    };

    for(unsigned long i = 0; i < ARRAY_SIZE(table); ++i) {
        if (!mx_strcmp(segment, table[i].morse)) 
            mx_printstr(table[i].ascii);
    }
}
