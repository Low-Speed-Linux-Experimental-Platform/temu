int test() {
    float a = 19.6;
    float d = 7.8;
    int c = 114;
    double e = 3.14;
    return (int) (a * d + c / e);
}

int main() {
    test();
    __asm__("ecall");
    return 0;
}