# /**
#  * @file CPE05_10929.cpp
#  * @author your name (you@domain.com)
#  * @brief d235: 10929 - You can say 11
#  * @version 0.1
#  * @date 2022-07-07
#  * @copyright Copyright (c) 2022
#  **/
while True:
    num = int(input())
    if num == 0:
        break
    if (num % 11 == 0):
        print(f'{num} is a multiple of 11.')
    else:
        print(f'{num} is not a multiple of 11.')
