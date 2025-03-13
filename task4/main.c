#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>



int is_correct(const char *value) {
    const char *corr_values[] = {"1c+", "2c+", "2c3", "4c", "8c", "16c"};
    int count = sizeof(corr_values)/sizeof(corr_values[0]);
    for (int i = 0; i < count; ++i) {
        if (strcmp(value, corr_values[i]) == 0)
            return 1;
    }
    return 0;
}

int main(int argc, char**argv) {
    static struct option long_opt[] = {
        {"elbrus", required_argument, 0, 'e'},
        {0, 0, 0, 0}
    };

    int opt, m_flag = 0, c_flag = 0, s_flag = 0, t_flag = 0, correct_flag = 1;
    char* elbrus_val = NULL;
    // char *incorrect_opt = NULL;
    char *non_options[argc];
    int count_non_opt = 0, elbrus_val_correct = 1;

    while((opt = getopt_long(argc, argv, "mcst", long_opt, NULL)) != -1) {
        switch(opt) {
            case 'm':
                m_flag = 1;
                break;
            case 'c':
                c_flag = 1;
                break;
            case 's':
                s_flag = 1;
                break;
            case 't':
                t_flag = 1;
                break;
            case 'e':
                elbrus_val = optarg;
                if (!is_correct(elbrus_val)) {
                    correct_flag = 0;
                    elbrus_val_correct = 0;
                }
                break;
            case '?':
                // correct_flag = 0;
                // incorrect_opt = argv[optind - 1];
                break;
            default:
                break;
        }
    }
    for (int i = optind; i < argc; ++i) {
        non_options[count_non_opt] = argv[i];
        ++count_non_opt;
    }
    if (correct_flag) {
        printf("Options are correct: ");
        if (t_flag) printf("t, ");
        if (m_flag) printf("m, ");
        if (c_flag) printf("c, ");
        if (s_flag) printf("s");
        
        if (elbrus_val) printf(", elbrus=%s", elbrus_val);
        if (count_non_opt) 
            printf(", non_options: ");
        for (int i = 0; i < count_non_opt; ++i) {
            printf("%s", non_options[i]);
            if (i < count_non_opt - 1) {
                printf(", ");
            }
        }
        printf(".\n");
    } else {
        
        // if (incorrect_opt) {
        //     printf("Options are incorrect.\n Incorrect option: %s\n", incorrect_opt);    //if opterr = 0; is added
        // }
        if (!elbrus_val_correct) {
            printf(" Incorrect value for --elbrus: %s", elbrus_val);
        }
        printf("\n");
    }
    return 0;
}