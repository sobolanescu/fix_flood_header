Search:

int CInputMain::Analyze(LPDESC d, BYTE bHeader, const char * c_pData)
{
	LPCHARACTER ch;

	if (!(ch = d->GetCharacter()))
	{
		sys_err("no character on desc");
		d->SetPhase(PHASE_CLOSE);
		return (0);
	}
  

Add:

#ifdef ENABLE_ANTI_HEADER_FLOOD
	if (ch && ch->IsPC() && bHeader != HEADER_CG_ITEM_PICKUP)
	{
		if (get_global_time() < ch->analyze_protect )
		{
			ch->analyze_protect_count = ch->analyze_protect_count + 1;
			
			if (ch->analyze_protect_count >= 300)
			{
				sys_err("HEADER_FLOOD_DETECTED: Name: %s Count: %d Header: %d", ch->GetName(), ch->analyze_protect_count, bHeader);
				ch->analyze_protect_count = 0;
				d->SetPhase(PHASE_CLOSE);
				return (0);
			}
		}
		else
			ch->analyze_protect_count = 0;
		
		ch->analyze_protect = get_global_time() + 1;
	}
#endif
