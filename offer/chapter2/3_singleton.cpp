class singleton{
public:
    static singleton& getInstance();
    
private:
    int value;
    singleton(){}
    singleton(int i):value(i){}    

};

singleton& singleton::getInstance(){
    static singleton a;
    return a;
}