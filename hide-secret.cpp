#include <cstring>

void hide_secret(char* const text, const char* const secret)
{
    if (text == nullptr || secret == nullptr)
        return;
    int secretLength = strlen(secret);
    if ( secretLength == 0)
        return;
    for (int i = 0; text[i] != '\0'; i++)
    {
        bool matched = true;
        bool needEnd = false;
        for (int j = i; j - i < secretLength; j++)
        {
            if (text[j] == '\0')
            {
                needEnd = true;
            }
            if (text[j] != secret[j - i])
            {
                matched = false;
                break;
            }
        }

        if (!matched)
        {
            continue;
        }
        if (needEnd)
        {
            break;
        }
        text[i] = '\x01';
    }

    int lastStart = -1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '\x01')
        {
            lastStart = i;
        }

        if (lastStart == -1)
        {
            continue;
        }

        if (i - lastStart < secretLength)
        {
            text[i] = 'x';
        }
    }
}
