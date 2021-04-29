//---------------------------------------------------------------------------
#ifndef CandidateH
#define CandidateH

//---------------------------------------------------------------------------
class Candidate {

    int id;
    String sex;
    String name;
    int age;
    int height;
    int weight;
    String hobby;
    String habbit;
    bool isFree;
    int maxAge;
    int minAge;
    int maxHeight;
    int minHeight;
    int maxWeight;
    int minWeight;
public:
    Candidate();

    ~Candidate();

    void setId(int id);

    int getId();

    void setAge(int age);

    int getAge();

    void setHeight(int height);

    int getHeight();

    void setWeight(int weight);

    int getWeight();

    void setName(String name);

    String getName();

    void setSex(String sex);

    String getSex();

    void setHabbit(String habbit);

    String getHabbit();

    void setHobby(String hobby);

    String getHobby();

    void setIsFree(int isFree);

    int getIsFree();

    void setMaxAge(int maxAge);

    int getMaxAge();

    void setMinAge(int minAge);

    int getMinAge();

    void setMaxHeight(int maxHeight);

    int getMaxHeight();

    void setMinHeight(int minHeight);

    int getMinHeight();

    void setMaxWeight(int maxWeight);

    int getMaxWeight();

    void setMinWeight(int minWeight);

    int getMinWeight();
};

#endif
