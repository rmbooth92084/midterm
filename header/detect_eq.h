//define local variable(s) here.  Use static keyword to keep local, e.g:
static int j;  // defines a local int named i



/*complete the state machine*/

void Detect_EQ()
{
    switch(detect_eq_state)
    {
        case DEQInit:
            if(~PINA >> 3 == 0)
		    detect_eq_state = detect;
	    else
		    detect_eq_state = DEQInit;
            break;
	case detect:
	    if(~PINA >> 3 == 0)
	    {
		    j = 0;
		    detect_eq_state = wait;
	    }
	    else
		    detect_eq_state = detect;
	    break;
	case wait:
	    if(~PINA >> 3 != 0 && j < 10)
	    	detect_eq_state = DEQInit;
	    else if (j >= 10)
	    {
		    j = 0;
		     detect_eq_state = DEQInit;
	    }
	    else
		    j++;
	    break;
	default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
	    tempB = tempB & 0xFD;
	    quake = 0;
            break;
	case detect:
	    tempB = tempB | 0x02;
	    quake = 1;
	    break;
        default:
            break;
    }
}
