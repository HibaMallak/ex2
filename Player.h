class Player
{
private:
    char* name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;
public:
    Player(char* name,int maxHP, int force);
    ~Player();
};

Player::~Player()
{
}
    
}

Player::Player( char* name,int maxHP=100, int force=5)
{
    this.name= name;
    this.maxHP= maxHP;
    this.force= force;
    this.coins=0;
    this.HP= maxHP;
    this.level=0;
}