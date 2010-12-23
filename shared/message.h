#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#define action_len 4
#define content_len 1000

struct message{
    char action[action_len];
    char content[content_len];
};

#endif // _MESSAGE_H_
