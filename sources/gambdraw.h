#include "gblock.h"
#include "gstring.h"
class GambitDrawSettings
{
private:
	void	UpdatePlayerColor(int pl);
	static void player_color_callback(wxListBox &ob,wxCommandEvent &ev);
	typedef struct {GambitDrawSettings *parent;wxListBox *color_item;} player_color_struct;
protected:
	static gBlock<int> player_colors;
public:
// Constructor
	GambitDrawSettings(void);
// Controls the color each player gets
	void	SetPlayerColor(int pl,int cl);
	int		GetPlayerColor(int pl) const;
// Allows to save/restore settings from file
	void	SaveOptions(char *f=0) const;
	void	LoadOptions(char *f);
// GUI Set colors
	void	PlayerColorDialog(gArray<gString> &);
};

