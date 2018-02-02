/*
 *Given a list of URIs to check for in a console argument, 
 *will attempt to rebuild URLs before providing the arg string lump.
 *
 * @param URIs        List of URIs to check for.
 * @param buffer      Buffer to write string lump to.
 * @param maxlen      Size of buffer.
 * @param truncated   If the buffer is full before it finishes writing the arg string, this will be set to true.
 *
 * @returns           Bytes written.
 */
stock int GetCmdArgStringUrl(const char[][] URIs, char[] buffer, int maxlen, bool &truncated)
{
    bool bAwaitingURL;
    bool bURIFound;
    char cArg[PLATFORM_MAX_PATH];
    int iArgLen = GetCmdArgs();
    int iBufferSize = sizeof(buffer[]);
    int iBytesWritten = 0;
    int iURICount = sizeof(URIs[][]);
    
    for (int i = 1; i < iArgLen; i++)
    {
        if (iBytesWritten >= iBufferSize)
        {
            truncated = true;
            return iBytesWritten;
        }
        
        GetCmdArg(i, cArg, sizeof(cArg));
        if (bAwaitingURL)
        {
            if (cArg[0] == '/' && cArg[1] == '/' && StrContains(cArg, "."))
            {
                StrCat(buffer, iBufferSize, ":");
            }

            bURIFound = false;
            bAwaitingURL = false;
        }
        else
        {
            for (int uri = 0; uri < iURICount; uri++)
            {
                if(StrEqual(cArg, URIs[uri], false))
                {
                    bURIFound = true;
                    break;
                }
            }            
        }
        
        if (bURIFound)
        {
            bAwaitingURL = true;
        }
        
        iBytesWritten += StrCat(buffer, iBufferSize, cArg);
    }
    
    truncated = false;
    return iBytesWritten;
}
