#include <streambuf>
#include <iostream>
#include <cctype>
using namespace std;

class ToUpperStreamBuf : public streambuf
{
public:
ToUpperStreamBuf(streambuf* wrapped) : _wrapped(wrapped)
{
}

protected:
int_type overflow(int_type ch)
{
if (traits_type::not_eof(ch))
ch = _wrapped->sputc(toupper(traits_type::to_char_type(ch)));
return ch;
}
int sync()
{
return _wrapped->pubsync();
}

private:
streambuf* _wrapped;
};

