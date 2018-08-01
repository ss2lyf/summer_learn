#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 1000;

struct student
{
    int score;
    int age;
    char name[100];
};

bool cmp(student a, student b)
{
    if (a.score != b.score)
    {
        return a.score < b.score;
    }
    else if (strcmp(a.name, b.name) != 0)
    {
        return strcmp(a.name, b.name) < 0;
    }
    else
    {
        return a.age < b.age;
    }
}

int main()
{
    student students[MAX];
    int n;

    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d%d", students[i].name,
                &students[i].age, &students[i].score);
        }
        std::sort(students, students + n, cmp);
        for (int i = 0; i < n; i++)
        {
            printf("%s %d %d\n", students[i].name,
                students[i].age, students[i].score);
        }
    }
    return 0;
}
