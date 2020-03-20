/*
 * Defines an Exception for when a comment is provided with a label.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"

#ifndef COMMENTHASLABELEXCEPTION_H
#define COMMENTHASLABELEXCEPTION_H

class CommentHasLabelException : public BaseException{
public:
    CommentHasLabelException()
        : BaseException("Comment statements cannot have labels")
    {
    }
};

#endif // COMMENTHASLABELEXCEPTION_H
