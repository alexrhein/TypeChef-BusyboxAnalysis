#include "/local/ifdeftoif/ifdeftoif/id2i_optionstruct.h"
static char ls_options[] __attribute__((aligned (1))) =  "Cadil1gnsxQAk" "cetu" "SXrv" "Fp" "L" "R" "h" "KZ" "T:w:";
static  void init_ls_options()  {
  int currentLength =  13;
  if ((id2i.config_ftpd || id2i.config_feature_ls_timestamps)) {
    (ls_options[currentLength] = 'c');
  }  
  if ((id2i.config_ftpd || id2i.config_feature_ls_timestamps)) {
    (ls_options[(currentLength + 1)] = 'e');
  }  
  if ((id2i.config_ftpd || id2i.config_feature_ls_timestamps)) {
    (ls_options[(currentLength + 2)] = 't');
  }  
  if ((id2i.config_ftpd || id2i.config_feature_ls_timestamps)) {
    (ls_options[(currentLength + 3)] = 'u');
  }  
  if ((id2i.config_ftpd || id2i.config_feature_ls_timestamps)) {
    (currentLength += 4);
  }  
  if (id2i.config_feature_ls_sortfiles) {
    (ls_options[currentLength] = 'S');
  }  
  if (id2i.config_feature_ls_sortfiles) {
    (ls_options[(currentLength + 1)] = 'X');
  }  
  if (id2i.config_feature_ls_sortfiles) {
    (ls_options[(currentLength + 2)] = 'r');
  }  
  if (id2i.config_feature_ls_sortfiles) {
    (ls_options[(currentLength + 3)] = 'v');
  }  
  if (id2i.config_feature_ls_sortfiles) {
    (currentLength += 4);
  }  
  if (id2i.config_feature_ls_filetypes) {
    (ls_options[currentLength] = 'F');
  }  
  if (id2i.config_feature_ls_filetypes) {
    (ls_options[(currentLength + 1)] = 'p');
  }  
  if (id2i.config_feature_ls_filetypes) {
    (currentLength += 2);
  }  
  if (id2i.config_feature_ls_followlinks) {
    (ls_options[currentLength] = 'L');
  }  
  if (id2i.config_feature_ls_followlinks) {
    (currentLength += 1);
  }  
  if (id2i.config_feature_ls_recursive) {
    (ls_options[currentLength] = 'R');
  }  
  if (id2i.config_feature_ls_recursive) {
    (currentLength += 1);
  }  
  if (id2i.config_feature_human_readable) {
    (ls_options[currentLength] = 'h');
  }  
  if (id2i.config_feature_human_readable) {
    (currentLength += 1);
  }  
  if ((id2i.config_feature_find_context || id2i.config_selinux)) {
    (ls_options[currentLength] = 'K');
  }  
  if ((id2i.config_feature_find_context || id2i.config_selinux)) {
    (ls_options[(currentLength + 1)] = 'Z');
  }  
  if ((id2i.config_feature_find_context || id2i.config_selinux)) {
    (currentLength += 2);
  }  
  if (id2i.config_feature_autowidth) {
    (ls_options[currentLength] = 'T');
  }  
  if (id2i.config_feature_autowidth) {
    (ls_options[(currentLength + 1)] = ':');
  }  
  if (id2i.config_feature_autowidth) {
    (ls_options[(currentLength + 2)] = 'W');
  }  
  if (id2i.config_feature_autowidth) {
    (ls_options[(currentLength + 3)] = ':');
  }  
  if (id2i.config_feature_autowidth) {
    (currentLength += 4);
  }  
  (ls_options[currentLength] = '\0');
}