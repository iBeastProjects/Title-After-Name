//Make changes like that:
void CPythonTextTail::ArrangeTextTail()
{
		[...]
		
		CGraphicTextInstance * pTitle = pTextTail->pTitleTextInstance;
		if (pTitle)
		{
			int iTitleWidth, iTitleHeight;
			pTitle->GetTextSize(&iTitleWidth, &iTitleHeight);

			fxAdd = 8.0f;

			if (LocaleService_IsEUROPE()) // µ¶ŔĎľî´Â ¸íÄŞŔĚ ±ćľî żŔ¸ĄÁ¤·Ä
			{
				if( GetDefaultCodePage() == CP_ARABIC )
				{
#ifndef ENABLE_TITLE_AFTER_NAME
					pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth - 4.0f, pTextTail->y, pTextTail->z);
#else
					pTitle->SetPosition(pTextTail->x + iNameWidth + iTitleWidth - 4.0f, pTextTail->y, pTextTail->z);
#endif
				}
				else
				{
#ifndef ENABLE_TITLE_AFTER_NAME
					pTitle->SetPosition(pTextTail->x - (iNameWidth / 2), pTextTail->y, pTextTail->z);
#else
					pTitle->SetPosition(pTextTail->x + iNameWidth + iTitleWidth, pTextTail->y, pTextTail->z);
#endif
				}
			}
			else
			{
#ifndef ENABLE_TITLE_AFTER_NAME
				pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - fxAdd, pTextTail->y, pTextTail->z);
#else
				pTitle->SetPosition(pTextTail->x + iNameWidth + iTitleWidth -fxAdd, pTextTail->y, pTextTail->z);
#endif
			}
			pTitle->Update();

			CGraphicTextInstance * pLevel = pTextTail->pLevelTextInstance;
			if (pLevel)
			{
				int iLevelWidth, iLevelHeight;
				pLevel->GetTextSize(&iLevelWidth, &iLevelHeight);

				if (LocaleService_IsEUROPE())
				{
					if( GetDefaultCodePage() == CP_ARABIC )
					{
						pLevel->SetPosition(pTextTail->x - (iNameWidth / 2) - iLevelWidth - iTitleWidth - 8.0f, pTextTail->y, pTextTail->z);
					}
					else
					{
#ifndef ENABLE_TITLE_AFTER_NAME
						pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth, pTextTail->y, pTextTail->z);
#else
						pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) + 4.0f, pTextTail->y, pTextTail->z);
#endif
					}
				}
				else
				{
					pLevel->SetPosition(pTextTail->x - (iNameWidth / 2) - fxAdd - iTitleWidth, pTextTail->y, pTextTail->z);
				}

				pLevel->Update();
			}
		}
		
		[...]
	}

	[...]
}