class Entity
{
public:
    virtual void Update(float delta) = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;
};