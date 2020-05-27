
//define local variable(s) here.  Use static keyword to keep local, e.g:
static int i = 1;  // defines a local int named i


/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:
            break;
        default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
		if(i % 10 == 0)
			tempB = tempB | 0x01;
		else
			tempB = tempB & 0xFE;
		i++;
		if(i > 10)
			i = 1;
            break;
        default:
            break;
    }
}
