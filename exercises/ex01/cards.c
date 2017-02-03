#include <stdio.h>
#include <stdlib.h>

void prompt_for_card(char *card_name) {
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

void determine_val(int *val, char *card_name) {
  switch(card_name[0]) {
  case 'K':
  case 'Q':
  case 'J':
    *val = 10;
    break;
  case 'A':
    *val = 11;
    break;
  case 'X':
    break;
  default:
    *val = atoi(card_name);
    if ((*val < 1) || (*val > 10)) {
      puts("I don't understand that value!");
    }
  }
}

void change_count(int *count, int val) {
  if ((val > 2) && (val < 7)) {
    *count = *count + 1;
  }
  else if (val == 10) {
    *count = *count - 1;
  }
}

int main() {
  char card_name[3];
  int count = 0;
  int val = 0;

  while (1) {
    prompt_for_card(card_name);
    if (*card_name == 'X') { break; }
    determine_val(&val, card_name);
    change_count(&count, val);
    printf("Current count: %i\n", count);
  }
  return 0;
}
