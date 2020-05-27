
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static char dir1 = 0x00;


/*complete the state machine*/

void Detect_ZC()
{
    switch(detect_zc_state)
    {
        case DZCInit:
		if(quake == 1)
			detect_zc_state = dir1;
		else
			detect_zc_state = DZCInit;
            break;
	case dir:
	    detect_zc_state = test;
	    break;
	case test:
	    if(dir1 == 0x00 && ((~PINA & 0x07) == 0x04))
		    detect_zc_state = test2;
	    else if(dir1 == 0x01 && ((~PINA & 0x07) == 0x05))
		    detect_zc_state = test2;
	    else if(dir1 == 0x02 && ((~PINA & 0x07) == 0x06))
		    detect_zc_state = test2;
	    else if(dir1 == 0x03 && ((~PINA & 0x07) == 0x07))
		    detect_zc_state = test2;
	    else if(dir1 == 0x04 && ((~PINA & 0x07) == 0x00))
		    detect_zc_state = test2;
	    else if(dir1 == 0x05 && ((~PINA & 0x07) == 0x01))
		    detect_zc_state = test2;
	    else if(dir1 == 0x06 && ((~PINA & 0x07) == 0x02))
		    detect_zc_state = test2;
	    else if(dir1 == 0x07 && ((~PINA & 0x07) == 0x03))
		    detect_zc_state = test2;
	    else
		    detect_zc_state = DZCInit;
	    break;
        
	case test2:
	    if(dir1 == 0x00 && ((~PINA & 0x07) == 0x04))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x01 && ((~PINA & 0x07) == 0x05))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x02 && ((~PINA & 0x07) == 0x06))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x03 && ((~PINA & 0x07) == 0x07))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x04 && ((~PINA & 0x07) == 0x00))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x05 && ((~PINA & 0x07) == 0x01))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x06 && ((~PINA & 0x07) == 0x02))
		    tempB = tempB | 0x04;
	    else if(dir1 == 0x07 && ((~PINA & 0x07) == 0x03))
		    tempB = tempB | 0x04;
	    else
		    tempB = tempB & 0xFB;
	    detect_zc_state = DZCInit;
	    break;
        default:
            detect_zc_state = DZCInit;
            break;
    }
    switch(detect_zc_state)
    {
        case DZCInit:
		    tempB = tempB & 0xFB;
            break;
        default:
            break;
    }
}
