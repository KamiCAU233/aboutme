#include <stdio.h>

int main()
{
    int head, foot;
    scanf("%d%d", &head, &foot);
    for (int rabbit = 0; rabbit <= head; rabbit++)
    {
        int chicken = head - rabbit;
        if (rabbit * 4 + chicken * 2 == foot)
        {
            printf("%d %d\n", chicken, rabbit);
            return 0;
        }
    }
}
