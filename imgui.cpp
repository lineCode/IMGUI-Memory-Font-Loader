// Heres the code for loading the font from momory using imgui
// for more info on imgui you can reach out here https://github.com/ocornut/imgui

ImFont* ImFontAtlas::AddFontDefault(const ImFontConfig* font_cfg_template)
{
	ImFontConfig font_cfg = font_cfg_template ? *font_cfg_template : ImFontConfig();
	if (!font_cfg_template)
	{
		font_cfg.OversampleH = font_cfg.OversampleV = 1;
		font_cfg.PixelSnapH = true;
	}
	if (font_cfg.Name[0] == '\0') strcpy(font_cfg.Name, "Courirer New.ttf, 13px"); //change font name 
	if (font_cfg.SizePixels <= 0.0f) font_cfg.SizePixels = 13.0f;
 
	const char* ttf_compressed_base85 = GetDefaultCompressedFontDataTTFBase85();
	ImFont* font = AddFontFromMemoryCompressedBase85TTF(ttf_compressed_base85, font_cfg.SizePixels, &font_cfg, GetGlyphRangesDefault());
	return font;
}
