#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

// посимвольное получение динамической строки с пробелами c получением её реальной длины
char *get_string(int *len) {
    *len = 0; // изначально строка пуста
    int capacity = 1; // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    char *s = (char*) malloc(sizeof(char)); // динамическая пустая строка

    char c = getchar(); // символ для чтения данных

    // читаем символы, пока не получим символ переноса строки (\n)
    while (c != '\n') {
        s[(*len)++] = c; // заносим в строку новый символ

        // если реальный размер больше размера контейнера, то увеличим его размер
        if (*len >= capacity) {
            capacity *= 2; // увеличиваем ёмкость строки в два раза
            s = (char*) realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью
        }

        c = getchar(); // считываем следующий символ
    }

    s[*len] = '\0'; // завершаем строку символом конца строки

    return s; // возвращаем указатель на считанную строку
}

// посимвольное получение динамической строки для флага с
char *get_string2(int *len2) {
    *len2 = 0;
    int capacity = 1;
    char *s2 = (char*) malloc(sizeof(char));

    char c2 = getchar();

    while (c2 != '\n') {
        s2[(*len2)++] = c2;
        if (*len2 >= capacity) {
            capacity *= 2;
            s2 = (char*) realloc(s2, capacity * sizeof(char));
        }

        c2 = getchar();
    }
    s2[*len2] = '\0';
    return s2;
}



char *reverse_string(char *str, int len)
{
    
    char temp;
    size_t k = len;
    for (int i = 0; i < len; i++)
    {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        k--;

        if(k == (len / 2))
        {
            break;
        }
    }
    
    return str;
}


char *up_symbol(char *str) {
    char *ptr=str;
    int num_pos = 1;

    while (*ptr) {
        str[num_pos] = putchar(toupper(str[num_pos]));
        num_pos = num_pos + 2;
        ++ptr;
    }
    
    return str;
}


char *order_str(char *str, int len) {
    
    //считаем количество каждых символов
    int k_nmbrs = 0, k_letters = 0, k_other = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] >= '0') && (str[i] <= '9'))
            k_nmbrs++;
        
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            k_letters++;
       
        if (! (str[i] >= '0' && (str[i] <= '9')) && (! ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))))
            k_other++;
    }
    
    //создаем массивы для каждого типа символов
    char numbers_str[k_nmbrs], letters_str[k_letters], other_str[k_other];
    int l_num = 0, l_str = 0, l_other = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            numbers_str[l_num] = str[i];
            l_num++;
        }
        
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            letters_str[l_str] = str[i];
            l_str++;
        }
        
        if (! (str[i] >= '0' && (str[i] <= '9')) && (! ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))) {
            other_str[l_other] = str[i];
            l_other++;
        }
    }
    
    int k2 = k_letters + k_nmbrs;
    
    //склеим эти три массива в один
    for (int i = 0; i < k_nmbrs; i++)
        str[i] = numbers_str[i];
        
    for (int i = k_nmbrs; i < k2; i++) {
        str[i] = letters_str[i - k_nmbrs];
    }
    
    for (int i = k2; i < len; i++) {
        str[i] = other_str[i - k2];
    }
    
    return str;
}



int main() {
    int len, len2; // длина строки
    printf("Введите строку: ");
    char *s = get_string(&len); // считываем динамическую строку
    char flag;
    printf("Введите флаг: ");
    scanf("-%c", &flag);
    printf("Вы ввели строку и флаг: %s, %c\n", s, flag);
    char *s2 = get_string2(&len2);
    
    switch (flag) {
    
    case 'l':
        printf("Длина строки: %d\n", len);
        break;
    
    case 'r':
        reverse_string(s, len);
        printf("Перевернутая строка:\n");
        for (int i=0; i <= len; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
        break;
        
    case 'u':
        up_symbol(s);
        printf("Все символы на нечетных позициях преобразованы в верхний регистр:\n");
        for (int i=0; i <= len; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
        break;

    case 'n':
        order_str(s, len);
        printf("Новая строка:\n");
        for (int i=0; i <= len; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
        break;
    
    case 'c':
        printf("Введите вторую строку: ");
        char *s2 = get_string(&len2);
        int len_dbl = len + len2;
        char new_str[len_dbl];
            
        printf("Новая строка:\n");
        for (int i = 0; i < len; i++) {
            new_str[i] = s[i];
            printf("%c", new_str[i]);
        }
        for (int i = len; i < len_dbl; i++) {
            new_str[i] = s2[i-len];
            printf("%c", new_str[i]);
        }
            
        break;
            
    }

    return 0;
}
