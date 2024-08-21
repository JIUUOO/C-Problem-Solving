#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *order2int(const char *order) {
  int *res = (int *)malloc(sizeof(int) * 2);
  if (!res) {
    printf("malloc failed.\n");
    return NULL;
  }
  res[0] = res[1] = 0;

  if (strcmp(order, "R") == 0) {
    res[0] = 1;
  } else if (strcmp(order, "L") == 0) {
    res[0] = -1;
  } else if (strcmp(order, "B") == 0) {
    res[1] = -1;
  } else if (strcmp(order, "T") == 0) {
    res[1] = 1;
  } else if (strcmp(order, "RT") == 0) {
    res[0] = 1;
    res[1] = 1;
  } else if (strcmp(order, "LT") == 0) {
    res[0] = -1;
    res[1] = 1;
  } else if (strcmp(order, "RB") == 0) {
    res[0] = 1;
    res[1] = -1;
  } else if (strcmp(order, "LB") == 0) {
    res[0] = -1;
    res[1] = -1;
  }

  return res;
}

bool move(char *pos, char *order) {
  int *orderPos = order2int(order);
  // printf("%d, %d\n", orderPos[0], orderPos[1]);

  // horizontal overflow
  if (!(pos[0] + orderPos[0] >= 'A' && pos[0] + orderPos[0] <= 'H')) {
    return false;
  }
  // vertical overflow
  if (!(atoi(&pos[1]) + orderPos[1] >= 1 && atoi(&pos[1]) + orderPos[1] <= 8)) {
    return false;
  }

  pos[0] += orderPos[0];
  pos[1] += orderPos[1];
  return true;
}

int main(void) {
  char posKing[3];
  char posStone[3];
  int num;
  scanf("%s %s %d", posKing, posStone, &num);

  char orderList[num][3];
  for (int i = 0; i < num; i++) {
    scanf("%s", orderList[i]);
  }

  char prevPosKing[3];
  for (int i = 0; i < num; i++) {
    memcpy(prevPosKing, posKing, 3);

    if (move(posKing, orderList[i])) {
      // move stone simultaneously
      if (strcmp(posKing, posStone) == 0) {
        if (!move(posStone, orderList[i])) {
          memcpy(posKing, prevPosKing, 3);
        }
      }
    }
  }

  printf("%s\n", posKing);
  printf("%s\n", posStone);

  return 0;
}