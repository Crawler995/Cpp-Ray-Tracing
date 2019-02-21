#ifndef COLOR__
#define COLOR__

class Color {
    public:
        Color(int r, int g, int b);
        Color copy();
        Color add(Color c);
        Color multiply(int a);
        Color modulate(Color c);

        int get_r();
        int get_g();
        int get_b();

        void set_r(int r);
        void set_g(int g);
        void set_b(int b);
    private:
        int R, G, B;
};

#endif