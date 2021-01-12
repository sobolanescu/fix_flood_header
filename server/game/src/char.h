Search:

	public:
		LPCHARACTER			FindCharacterInView(const char * name, bool bFindPCOnly);
		void				UpdatePacket();
    


Add:

#ifdef ENABLE_ANTI_HEADER_FLOOD
		int					analyze_protect; 
		int					analyze_protect_count;
#endif
