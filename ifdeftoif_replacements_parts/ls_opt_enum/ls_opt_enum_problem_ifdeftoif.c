#include "/local/ifdeftoif/ifdeftoif/id2i_optionstruct.h"
enum  {
  OPT_g = (1 << 6),
  OPT_Q = (1 << 10)
} ;
static int OPTBIT_color =  0;
static int OPT_color =  0;
void init_OPT_enumVars()  {
  (OPTBIT_color = 13);
  if ((id2i.config_ftpd || id2i.config_feature_ls_timestamps)) {
    (OPTBIT_color += 4);
  }  
  if (id2i.config_feature_ls_sortfiles) {
    (OPTBIT_color += 4);
  }  
  if (id2i.config_feature_ls_filetypes) {
    (OPTBIT_color += 2);
  }  
  if (id2i.config_feature_ls_followlinks) {
    (OPTBIT_color += 1);
  }  
  if (id2i.config_feature_ls_recursive) {
    (OPTBIT_color += 1);
  }  
  if (id2i.config_feature_human_readable) {
    (OPTBIT_color += 1);
  }  
  if ((id2i.config_feature_find_context || id2i.config_selinux)) {
    (OPTBIT_color += 2);
  }  
  if (id2i.config_feature_autowidth) {
    (OPTBIT_color += 2);
  }  
  (OPT_color = (1 << OPTBIT_color));
}