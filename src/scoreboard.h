#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class Scoreboard {
    public:
        Scoreboard();
        void update_p1(int score);
        int p1();
        void update_p2(int score);
        int p2();
        
    protected:
        int _p1;
        int _p2;
};

#endif
