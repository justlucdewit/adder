enum tokenTypes
{
    Integer,
    Float,
    Operator,
    String,
    Unknown
};

struct token
{
    enum tokenTypes type;
    char *value;
};

char *getTokenType(enum tokenTypes type)
{
    switch (type)
    {
    case Integer:
        return "Integer";
    case Float:
        return "Float";
    case Operator:
        return "Operator";
    case Unknown:
        return "Unknown";
    case String:
        return "String";
    default:
        return "Extreme unkown";
    }
}