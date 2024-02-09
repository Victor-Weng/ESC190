typedef struct pyint {
    int* buffer; // buffer is a pointer to an array of integers
    int length;
} PyIntObject;