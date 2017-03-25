#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <vector>
#include "ident.h"

class Feedback : public Ident
{
public:
    Feedback();
    Feedback(string te, string ta, int cid, int p);
    ~Feedback();

    string text;
    string tag;
    int codeId;
    int position;
};

#endif // FEEDBACK_H
