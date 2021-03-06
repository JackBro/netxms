CREATE TABLE metadata
(
  var_name varchar(63) not null,
  var_value varchar(255) not null,
  PRIMARY KEY(var_name)
) ;
CREATE TABLE config
(
  var_name varchar(63) not null,
  var_value varchar(2000) null,
  is_visible integer not null default 1,
  need_server_restart integer not null default 0,
  data_type char(1) not null default 'S',
  is_public char(1) not null default 'N',
  description varchar(255) null,
  possible_values LONG VARCHAR null,
  PRIMARY KEY(var_name)
) ;
CREATE TABLE config_clob
(
  var_name varchar(63) not null,
  var_value LONG VARCHAR null,
  PRIMARY KEY(var_name)
) ;
CREATE TABLE users
(
  id integer not null,
  guid varchar(36) not null,
  name varchar(63) not null,
  password varchar(127) not null,
  system_access BIGINT not null,
  flags integer not null,
  full_name varchar(127) null,
  description varchar(255) null,
  grace_logins integer not null,
  auth_method integer not null,
  cert_mapping_method integer not null,
  cert_mapping_data LONG VARCHAR null,
  auth_failures integer not null,
  last_passwd_change integer not null,
  min_passwd_length integer not null,
  disabled_until integer not null,
  last_login integer not null,
  password_history LONG VARCHAR null,
  xmpp_id varchar(127) null,
  ldap_dn LONG VARCHAR null,
  ldap_unique_id varchar(64) null,
  PRIMARY KEY(id)
) ;
CREATE TABLE user_groups
(
  id integer not null,
  guid varchar(36) not null,
  name varchar(63) not null,
  system_access BIGINT not null,
  flags integer not null,
  description varchar(255),
  ldap_dn LONG VARCHAR null,
  ldap_unique_id varchar(64) null,
  PRIMARY KEY(id)
) ;
CREATE TABLE user_group_members
(
  group_id integer not null,
  user_id integer not null,
  PRIMARY KEY(group_id,user_id)
) ;
CREATE TABLE user_profiles
(
  user_id integer not null,
  var_name varchar(255) not null,
  var_value LONG VARCHAR not null,
  PRIMARY KEY(user_id,var_name)
) ;
CREATE TABLE userdb_custom_attributes
(
  object_id integer not null,
  attr_name varchar(255) not null,
  attr_value LONG VARCHAR not null,
  PRIMARY KEY(object_id,attr_name)
) ;
CREATE TABLE object_properties
(
  object_id integer not null,
  guid varchar(36) not null,
  name varchar(63) not null,
  status integer not null,
  is_deleted integer not null,
  is_system integer not null,
  last_modified integer not null,
  inherit_access_rights integer not null,
  status_calc_alg integer not null,
  status_prop_alg integer not null,
  status_fixed_val integer not null,
  status_shift integer not null,
  status_translation varchar(8) not null,
  status_single_threshold integer not null,
  status_thresholds varchar(8) not null,
  comments LONG VARCHAR null,
  location_type integer not null,
  latitude varchar(20),
  longitude varchar(20),
  location_accuracy integer not null,
  location_timestamp integer not null,
  image varchar(36) not null,
  submap_id integer not null,
  country varchar(63) null,
  city varchar(63) null,
  street_address varchar(255) null,
  postcode varchar(31) null,
  maint_mode char(1) not null,
  maint_event_id BIGINT not null,
  PRIMARY KEY(object_id)
) ;
CREATE TABLE object_custom_attributes
(
  object_id integer not null,
  attr_name varchar(127) not null,
  attr_value LONG VARCHAR null,
  PRIMARY KEY(object_id,attr_name)
) ;
CREATE INDEX idx_ocattr_oid ON object_custom_attributes(object_id);
CREATE TABLE zones
(
  id integer not null,
  zone_guid integer not null,
  proxy_node integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE mobile_devices
(
  id integer not null,
  device_id varchar(64) not null,
  vendor varchar(64) null,
  model varchar(128) null,
  serial_number varchar(64) null,
  os_name varchar(32) null,
  os_version varchar(64) null,
  user_id varchar(64) null,
  battery_level integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE access_points
(
  id integer not null,
  node_id integer not null,
  mac_address varchar(12) null,
  vendor varchar(64) null,
  model varchar(128) null,
  serial_number varchar(64) null,
  ap_state integer not null,
  ap_index integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE racks
(
  id integer not null,
  height integer not null,
  top_bottom_num char(1) not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE chassis
(
  id integer not null,
  controller_id integer not null,
  flags integer not null,
  rack_id integer not null,
  rack_image varchar(36) null,
  rack_position integer not null,
  rack_height integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE nodes
(
  id integer not null,
  primary_name varchar(255) null,
  primary_ip varchar(48) not null,
  node_flags integer not null,
  runtime_flags integer not null,
  snmp_version integer not null,
  snmp_port integer not null,
  community varchar(127) null,
  usm_auth_password varchar(127) null,
  usm_priv_password varchar(127) null,
  usm_methods integer not null,
  snmp_oid varchar(255) null,
  auth_method integer not null,
  secret varchar(64) null,
  agent_port integer not null,
  status_poll_type integer not null,
  agent_version varchar(63) null,
  platform_name varchar(63) null,
  poller_node_id integer not null,
  zone_guid integer not null,
  proxy_node integer not null,
  snmp_proxy integer not null,
  icmp_proxy integer not null,
  required_polls integer not null,
  uname varchar(255) null,
  use_ifxtable integer not null,
  snmp_sys_name varchar(127) null,
  snmp_sys_contact varchar(127) null,
  snmp_sys_location varchar(127) null,
  bridge_base_addr varchar(15) null,
  down_since integer not null,
  boot_time integer not null,
  driver_name varchar(32) null,
  rack_image varchar(36) null,
  rack_position integer not null,
  rack_height integer not null,
  rack_id integer not null,
  chassis_id integer not null,
  agent_cache_mode char(1) not null,
  last_agent_comm_time integer not null,
  syslog_msg_count BIGINT not null,
  snmp_trap_count BIGINT not null,
  node_type integer not null,
  node_subtype varchar(127) null,
  ssh_login varchar(63) null,
  ssh_password varchar(63) null,
  ssh_proxy integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE clusters
(
  id integer not null,
  cluster_type integer not null,
  zone_guid integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE cluster_members
(
  cluster_id integer not null,
  node_id integer not null,
  PRIMARY KEY(cluster_id,node_id)
) ;
CREATE TABLE cluster_sync_subnets
(
  cluster_id integer not null,
  subnet_addr varchar(48) not null,
  subnet_mask integer not null,
  PRIMARY KEY(cluster_id,subnet_addr)
) ;
CREATE TABLE cluster_resources
(
  cluster_id integer not null,
  resource_id integer not null,
  resource_name varchar(255),
  ip_addr varchar(48) not null,
  current_owner integer not null,
  PRIMARY KEY(cluster_id,resource_id)
) ;
CREATE TABLE subnets
(
  id integer not null,
  ip_addr varchar(48) not null,
  ip_netmask integer not null,
  zone_guid integer not null,
  synthetic_mask integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE interfaces
(
  id integer not null,
  node_id integer not null,
  flags integer not null,
  if_type integer not null,
  if_index integer not null,
  mtu integer not null,
  speed BIGINT not null,
  bridge_port integer not null,
  phy_slot integer not null,
  phy_port integer not null,
  peer_node_id integer not null,
  peer_if_id integer not null,
  peer_proto integer not null,
  mac_addr varchar(12) not null,
  required_polls integer not null,
  admin_state integer not null,
  oper_state integer not null,
  dot1x_pae_state integer not null,
  dot1x_backend_state integer not null,
  description varchar(255) null,
  alias varchar(255) null,
  iftable_suffix varchar(127) null,
  PRIMARY KEY(id)
) ;
CREATE TABLE interface_address_list
(
  iface_id integer not null,
  ip_addr varchar(48) not null,
  ip_netmask integer not null,
  PRIMARY KEY(iface_id,ip_addr)
) ;
CREATE TABLE network_services
(
  id integer not null,
  node_id integer not null,
  service_type integer not null,
  ip_bind_addr varchar(48) not null,
  ip_proto integer not null,
  ip_port integer not null,
  check_request LONG VARCHAR null,
  check_responce LONG VARCHAR null,
  poller_node_id integer not null,
  required_polls integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE vpn_connectors
(
  id integer not null,
  node_id integer not null,
  peer_gateway integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE vpn_connector_networks
(
  vpn_id integer not null,
  network_type integer not null,
  ip_addr varchar(48) not null,
  ip_netmask integer not null,
  PRIMARY KEY(vpn_id,ip_addr)
) ;
CREATE TABLE object_containers
(
  id integer not null,
  object_class integer not null,
  flags integer not null,
  auto_bind_filter LONG VARCHAR null,
  PRIMARY KEY(id)
) ;
CREATE TABLE conditions
(
  id integer not null,
  activation_event integer not null,
  deactivation_event integer not null,
  source_object integer not null,
  active_status integer not null,
  inactive_status integer not null,
  script LONG VARCHAR not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE cond_dci_map
(
  condition_id integer not null,
  sequence_number integer not null,
  dci_id integer not null,
  node_id integer not null,
  dci_func integer not null,
  num_polls integer not null,
  PRIMARY KEY(condition_id,sequence_number)
) ;
CREATE TABLE templates
(
  id integer not null,
  version integer not null,
  flags integer not null,
  apply_filter LONG VARCHAR null,
  PRIMARY KEY(id)
) ;
CREATE TABLE dct_node_map
(
  template_id integer not null,
  node_id integer not null,
  PRIMARY KEY(template_id,node_id)
) ;
CREATE TABLE nsmap
(
  subnet_id integer not null,
  node_id integer not null,
  PRIMARY KEY(subnet_id,node_id)
) ;
CREATE TABLE container_members
(
  container_id integer not null,
  object_id integer not null,
  PRIMARY KEY(container_id,object_id)
) ;
CREATE TABLE acl
(
  object_id integer not null,
  user_id integer not null,
  access_rights integer not null,
  PRIMARY KEY(object_id,user_id)
) ;
CREATE TABLE trusted_nodes
(
  source_object_id integer not null,
  target_node_id integer not null,
  PRIMARY KEY(source_object_id,target_node_id)
) ;
CREATE TABLE items
(
  item_id integer not null,
  node_id integer not null,
  template_id integer not null,
  template_item_id integer not null,
  guid varchar(36) not null,
  name varchar(1023) null,
  description varchar(255) null,
  flags integer not null,
  source integer not null,
  snmp_port integer not null,
  datatype integer not null,
  polling_interval integer not null,
  retention_time integer not null,
  status integer not null,
  snmp_raw_value_type integer not null,
  delta_calculation integer not null,
  transformation LONG VARCHAR,
  instance varchar(255) null,
  system_tag varchar(255) null,
  resource_id integer not null,
  proxy_node integer not null,
  base_units integer not null,
  unit_multiplier integer not null,
  custom_units_name varchar(63) null,
  perftab_settings LONG VARCHAR null,
  instd_method integer not null,
  instd_data varchar(255) null,
  instd_filter LONG VARCHAR null,
  samples integer not null,
  comments LONG VARCHAR null,
  PRIMARY KEY(item_id)
) ;
CREATE INDEX idx_items_node_id ON items(node_id);
CREATE TABLE dc_tables
(
  item_id integer not null,
  node_id integer not null,
  template_id integer not null,
  template_item_id integer not null,
  guid varchar(36) not null,
  name varchar(1023) null,
  description varchar(255) null,
  flags integer not null,
  source integer not null,
  snmp_port integer not null,
  polling_interval integer not null,
  retention_time integer not null,
  status integer not null,
  system_tag varchar(255) null,
  resource_id integer not null,
  proxy_node integer not null,
  perftab_settings LONG VARCHAR null,
  transformation_script LONG VARCHAR null,
  comments LONG VARCHAR null,
  PRIMARY KEY(item_id)
) ;
CREATE INDEX idx_dc_tables_node_id ON dc_tables(node_id);
CREATE TABLE dc_table_columns
(
  table_id integer not null,
  sequence_number integer not null,
  column_name varchar(63) not null,
  snmp_oid varchar(1023) null,
  flags integer not null,
  display_name varchar(255) null,
  PRIMARY KEY(table_id,column_name)
) ;
CREATE TABLE dct_column_names
(
  column_id integer not null,
  column_name varchar(63) not null,
  PRIMARY KEY(column_id)
) ;
CREATE TABLE dct_thresholds
(
  id integer not null,
  table_id integer not null,
  sequence_number integer not null,
  activation_event integer not null,
  deactivation_event integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE dct_threshold_conditions
(
  threshold_id integer not null,
  group_id integer not null,
  sequence_number integer not null,
  column_name varchar(63) null,
  check_operation integer not null,
  check_value varchar(255) null,
  PRIMARY KEY(threshold_id,group_id,sequence_number)
) ;
CREATE TABLE dci_schedules
(
  schedule_id integer not null,
  item_id integer not null,
  schedule varchar(255) null,
  PRIMARY KEY(item_id,schedule_id)
) ;
CREATE TABLE raw_dci_values
(
  item_id integer not null,
  raw_value varchar(255) null,
  transformed_value varchar(255) null,
  last_poll_time integer not null,
  PRIMARY KEY(item_id)
) ;
CREATE TABLE event_cfg
(
  event_code integer not null,
  event_name varchar(63) not null,
  guid varchar(36) not null,
  severity integer not null,
  flags integer not null,
  message varchar(2000) null,
  description LONG VARCHAR null,
  PRIMARY KEY(event_code)
) ;
CREATE TABLE event_log
(
  event_id BIGINT not null,
  event_code integer not null,
  event_timestamp integer not null,
  event_source integer not null,
  dci_id integer not null,
  event_severity integer not null,
  event_message varchar(2000) null,
  root_event_id BIGINT not null,
  user_tag varchar(63) null,
  PRIMARY KEY(event_id)
) ;
CREATE INDEX idx_event_log_event_timestamp ON event_log(event_timestamp);
CREATE INDEX idx_event_log_source ON event_log(event_source);
CREATE INDEX idx_event_log_root_id ON event_log(root_event_id);
CREATE TABLE actions
(
  action_id integer not null,
  action_name varchar(63) not null,
  action_type integer not null,
  is_disabled integer not null,
  rcpt_addr varchar(255) null,
  email_subject varchar(255) null,
  action_data LONG VARCHAR null,
  PRIMARY KEY(action_id)
) ;
CREATE TABLE event_groups
(
  id integer not null,
  name varchar(63) not null,
  description varchar(255) not null,
  range_start integer not null,
  range_end integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE event_group_members
(
  group_id integer not null,
  event_code integer not null,
  PRIMARY KEY(group_id,event_code)
) ;
CREATE TABLE event_policy
(
  rule_id integer not null,
  rule_guid varchar(36) not null,
  flags integer not null,
  comments LONG VARCHAR null,
  script LONG VARCHAR null,
  alarm_message varchar(2000) null,
  alarm_severity integer not null,
  alarm_key varchar(255) null,
  alarm_timeout integer not null,
  alarm_timeout_event integer not null,
  situation_id integer not null,
  situation_instance varchar(255) null,
  PRIMARY KEY(rule_id)
) ;
CREATE TABLE policy_source_list
(
  rule_id integer not null,
  object_id integer not null,
  PRIMARY KEY(rule_id,object_id)
) ;
CREATE TABLE policy_event_list
(
  rule_id integer not null,
  event_code integer not null,
  PRIMARY KEY(rule_id,event_code)
) ;
CREATE TABLE policy_action_list
(
  rule_id integer not null,
  action_id integer not null,
  PRIMARY KEY(rule_id,action_id)
) ;
CREATE TABLE policy_situation_attr_list
(
  rule_id integer not null,
  situation_id integer not null,
  attr_name varchar(255) not null,
  attr_value varchar(255) null,
  PRIMARY KEY(rule_id,situation_id,attr_name)
) ;
CREATE TABLE thresholds
(
  threshold_id integer not null,
  item_id integer not null,
  sequence_number integer not null,
  fire_value varchar(255) null,
  rearm_value varchar(255) null,
  check_function integer not null,
  check_operation integer not null,
  sample_count integer not null,
  script LONG VARCHAR null,
  event_code integer not null,
  rearm_event_code integer not null,
  repeat_interval integer not null,
  current_state integer not null,
  current_severity integer not null,
  match_count integer not null,
  last_event_timestamp integer not null,
  PRIMARY KEY(threshold_id)
) ;
CREATE INDEX idx_thresholds_item_id ON thresholds(item_id);
CREATE INDEX idx_thresholds_sequence ON thresholds(sequence_number);
CREATE TABLE alarms
(
  alarm_id integer not null,
  alarm_state integer not null,
  hd_state integer not null,
  hd_ref varchar(63) null,
  creation_time integer not null,
  last_change_time integer not null,
  source_object_id integer not null,
  source_event_code integer not null,
  source_event_id BIGINT not null,
  dci_id integer not null,
  message varchar(2000) null,
  original_severity integer not null,
  current_severity integer not null,
  repeat_count integer not null,
  alarm_key varchar(255) null,
  ack_by integer not null,
  resolved_by integer not null,
  term_by integer not null,
  timeout integer not null,
  timeout_event integer not null,
  ack_timeout integer not null,
  PRIMARY KEY(alarm_id)
) ;
CREATE TABLE alarm_notes
(
  note_id integer not null,
  alarm_id integer not null,
  change_time integer not null,
  user_id integer not null,
  note_text LONG VARCHAR null,
  PRIMARY KEY(note_id)
) ;
CREATE INDEX idx_alarm_notes_alarm_id ON alarm_notes(alarm_id);
CREATE TABLE alarm_events
(
  alarm_id integer not null,
  event_id BIGINT not null,
  event_code integer not null,
  event_name varchar(63) null,
  severity integer not null,
  source_object_id integer not null,
  event_timestamp integer not null,
  message varchar(2000) null,
  PRIMARY KEY(alarm_id,event_id)
) ;
CREATE INDEX idx_alarm_events_alarm_id ON alarm_events(alarm_id);
CREATE TABLE snmp_trap_cfg
(
  trap_id integer not null,
  snmp_oid varchar(255),
  event_code integer not null,
  user_tag varchar(63),
  description varchar(255),
  PRIMARY KEY(trap_id)
) ;
CREATE TABLE snmp_trap_pmap
(
  trap_id integer not null,
  parameter integer not null,
  flags integer not null,
  snmp_oid varchar(255) null,
  description varchar(255) null,
  PRIMARY KEY(trap_id,parameter)
) ;
CREATE TABLE agent_pkg
(
  pkg_id integer not null,
  pkg_name varchar(63),
  version varchar(31),
  platform varchar(63),
  pkg_file varchar(255),
  description varchar(255),
  PRIMARY KEY(pkg_id)
) ;
CREATE TABLE object_tools
(
  tool_id integer not null,
  guid varchar(36) not null,
  tool_name varchar(255) null,
  tool_type integer not null,
  tool_data LONG VARCHAR null,
  description varchar(255) null,
  flags integer not null,
  tool_filter LONG VARCHAR null,
  confirmation_text varchar(255) null,
  command_name varchar(255) null,
  command_short_name varchar(31) null,
  icon LONG VARCHAR null,
  PRIMARY KEY(tool_id)
) ;
CREATE TABLE object_tools_acl
(
  tool_id integer not null,
  user_id integer not null,
  PRIMARY KEY(tool_id,user_id)
) ;
CREATE TABLE object_tools_table_columns
(
  tool_id integer not null,
  col_number integer not null,
  col_name varchar(255) null,
  col_oid varchar(255) null,
  col_format integer,
  col_substr integer,
  PRIMARY KEY(tool_id,col_number)
) ;
CREATE TABLE object_tools_input_fields
(
  tool_id integer not null,
  name varchar(31) not null,
  input_type char(1) not null,
  display_name varchar(127) null,
  sequence_num integer not null,
  config LONG VARCHAR null,
  PRIMARY KEY(tool_id,name)
) ;
CREATE TABLE syslog
(
  msg_id BIGINT not null,
  msg_timestamp integer not null,
  facility integer not null,
  severity integer not null,
  source_object_id integer not null,
  hostname varchar(127) null,
  msg_tag varchar(32) null,
  msg_text LONG VARCHAR null,
  PRIMARY KEY(msg_id)
) ;
CREATE INDEX idx_syslog_msg_timestamp ON syslog(msg_timestamp);
CREATE TABLE script_library
(
  script_id integer not null,
  script_name varchar(255) not null,
  script_code LONG VARCHAR null,
  PRIMARY KEY(script_id)
) ;
CREATE TABLE snmp_trap_log
(
  trap_id BIGINT not null,
  trap_timestamp integer not null,
  ip_addr varchar(48) not null,
  object_id integer not null,
  trap_oid varchar(255) not null,
  trap_varlist LONG VARCHAR null,
  PRIMARY KEY(trap_id)
) ;
CREATE INDEX idx_snmp_trap_log_tt ON snmp_trap_log(trap_timestamp);
CREATE TABLE agent_configs
(
  config_id integer not null,
  config_name varchar(255) not null,
  config_file LONG VARCHAR not null,
  config_filter LONG VARCHAR not null,
  sequence_number integer not null,
  PRIMARY KEY(config_id)
) ;
CREATE TABLE address_lists
(
  list_type integer not null,
  community_id integer not null,
  addr_type integer not null,
  addr1 varchar(48) not null,
  addr2 varchar(48) not null,
  PRIMARY KEY(list_type,community_id,addr_type,addr1,addr2)
) ;
CREATE INDEX idx_address_lists_list_type ON address_lists(list_type);
CREATE TABLE graphs
(
  graph_id integer not null,
  owner_id integer not null,
  flags integer not null,
  name varchar(255) not null,
  config LONG VARCHAR null,
  filters LONG VARCHAR null,
  PRIMARY KEY(graph_id)
) ;
CREATE TABLE graph_acl
(
  graph_id integer not null,
  user_id integer not null,
  user_rights integer not null,
  PRIMARY KEY(graph_id,user_id)
) ;
CREATE TABLE certificates
(
  cert_id integer not null,
  cert_type integer not null,
  cert_data LONG VARCHAR not null,
  subject LONG VARCHAR not null,
  comments LONG VARCHAR not null,
  PRIMARY KEY(cert_id)
) ;
CREATE TABLE audit_log
(
  record_id integer not null,
  timestamp integer not null,
  subsystem varchar(32) not null,
  success integer not null,
  user_id integer not null,
  workstation varchar(63) not null,
  session_id integer not null,
  object_id integer not null,
  message LONG VARCHAR null,
  PRIMARY KEY(record_id)
) ;
CREATE TABLE situations
(
  id integer not null,
  name varchar(127) not null,
  comments LONG VARCHAR not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE snmp_communities
(
  id integer not null,
  community varchar(255) null,
  PRIMARY KEY(id)
) ;
CREATE TABLE ap_common
(
  id integer not null,
  policy_type integer not null,
  version integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE ap_bindings
(
  policy_id integer not null,
  node_id integer not null,
  PRIMARY KEY(policy_id,node_id)
) ;
CREATE TABLE ap_config_files
(
  policy_id integer not null,
  file_content LONG VARCHAR null,
  PRIMARY KEY(policy_id)
) ;
CREATE TABLE ap_log_parser
(
  policy_id integer not null,
  file_content LONG VARCHAR null,
  PRIMARY KEY(policy_id)
) ;
CREATE TABLE usm_credentials
(
  id integer not null,
  user_name varchar(255) not null,
  auth_method integer not null,
  priv_method integer not null,
  auth_password varchar(255),
  priv_password varchar(255),
  PRIMARY KEY(id)
) ;
CREATE TABLE network_maps
(
  id integer not null,
  map_type integer not null,
  layout integer not null,
  seed integer not null,
  radius integer not null,
  background varchar(36) null,
  bg_latitude varchar(20) null,
  bg_longitude varchar(20) null,
  bg_zoom integer null,
  flags integer not null,
  bg_color integer not null,
  link_color integer not null,
  link_routing integer not null,
  object_display_mode integer not null,
  filter LONG VARCHAR null,
  PRIMARY KEY(id)
) ;
CREATE TABLE network_map_elements
(
  map_id integer not null,
  element_id integer not null,
  element_type integer not null,
  element_data LONG VARCHAR not null,
  flags integer not null,
  PRIMARY KEY(map_id,element_id)
) ;
CREATE TABLE network_map_links
(
  map_id integer not null,
  element1 integer not null,
  element2 integer not null,
  link_type integer not null,
  link_name varchar(255) null,
  connector_name1 varchar(255) null,
  connector_name2 varchar(255) null,
  element_data LONG VARCHAR null,
  flags integer not null
) ;
CREATE INDEX idx_network_map_links_map_id ON network_map_links(map_id);
CREATE TABLE images
(
  guid varchar(36) not null,
  name varchar(63) not null,
  category varchar(63) not null,
  mimetype varchar(32) not null,
  protected integer default 0,
  PRIMARY KEY(guid),
  UNIQUE(name, category)
) ;
CREATE TABLE dashboards
(
  id integer not null,
  num_columns integer not null,
  options integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE dashboard_elements
(
  dashboard_id integer not null,
  element_id integer not null,
  element_type integer not null,
  element_data LONG VARCHAR null,
  layout_data LONG VARCHAR null,
  PRIMARY KEY(dashboard_id,element_id)
) ;
CREATE TABLE dashboard_associations
(
  object_id integer not null,
  dashboard_id integer not null,
  PRIMARY KEY(object_id,dashboard_id)
) ;
CREATE TABLE business_services
(
  service_id integer not null,
  PRIMARY KEY(service_id)
) ;
CREATE TABLE slm_checks
(
  id integer not null,
  type integer not null,
  content LONG VARCHAR null,
  threshold_id integer not null,
  reason varchar(255) null,
  is_template integer not null,
  template_id integer not null,
  current_ticket integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE node_links
(
  nodelink_id integer not null,
  node_id integer not null,
  PRIMARY KEY(nodelink_id)
) ;
CREATE TABLE slm_agreements
(
  agreement_id integer not null,
  service_id integer not null,
  org_id integer not null,
  uptime varchar(63) not null,
  period integer not null,
  start_date integer not null,
  notes varchar(255),
  PRIMARY KEY(agreement_id)
) ;
CREATE TABLE slm_tickets
(
  ticket_id integer not null,
  service_id integer not null,
  check_id integer not null,
  create_timestamp integer not null,
  close_timestamp integer not null,
  reason varchar(255) null,
  PRIMARY KEY(ticket_id)
) ;
CREATE TABLE slm_service_history
(
  record_id integer not null,
  service_id integer not null,
  change_timestamp integer not null,
  new_status integer not null,
  PRIMARY KEY(record_id)
) ;
CREATE TABLE organizations
(
  id integer not null,
  parent_id integer not null,
  org_type integer not null,
  name varchar(63) not null,
  description varchar(255),
  manager integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE persons
(
  id integer not null,
  org_id integer not null,
  first_name varchar(63),
  last_name varchar(63),
  title varchar(255),
  status integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE job_history
(
  id integer not null,
  time_created integer not null,
  time_started integer not null,
  time_finished integer not null,
  job_type varchar(127) null,
  description varchar(255) null,
  additional_info varchar(255) null,
  node_id integer not null,
  user_id integer not null,
  status integer not null,
  failure_message varchar(255) null,
  PRIMARY KEY(id)
) ;
CREATE TABLE licenses
(
  id integer not null,
  content LONG VARCHAR null,
  PRIMARY KEY(id)
) ;
CREATE TABLE mapping_tables
(
  id integer not null,
  name varchar(63) not null,
  flags integer not null,
  description varchar(4000) null,
  PRIMARY KEY(id)
) ;
CREATE TABLE mapping_data
(
  table_id integer not null,
  md_key varchar(63) not null,
  md_value varchar(255) null,
  description varchar(4000) null,
  PRIMARY KEY(table_id,md_key)
) ;
CREATE TABLE dci_summary_tables
(
  id integer not null,
  guid varchar(36) not null,
  menu_path varchar(255) null,
  title varchar(127) null,
  node_filter LONG VARCHAR null,
  flags integer not null,
  columns LONG VARCHAR null,
  PRIMARY KEY(id)
) ;
CREATE TABLE scheduled_tasks
(
  id integer not null,
  taskId varchar(255) null,
  schedule varchar(127) null,
  params varchar(1023) null,
  execution_time integer not null,
  last_execution_time integer not null,
  flags integer not null,
  owner integer not null,
  object_id integer not null,
  PRIMARY KEY(id)
) ;
CREATE TABLE zmq_subscription
(
  object_id integer not null,
  subscription_type char(1) not null,
  ignore_items integer not null,
  items LONG VARCHAR,
  PRIMARY KEY(object_id, subscription_type)
) ;
CREATE TABLE currency_codes
(
 numeric_code char(3) not null,
 alpha_code char(3) not null,
 description varchar(127) not null,
 exponent integer not null,
 PRIMARY KEY(numeric_code)
) ;
CREATE TABLE country_codes
(
 numeric_code char(3) not null,
 alpha_code char(2) not null,
 alpha3_code char(3) not null,
 name varchar(127) not null,
 PRIMARY KEY(numeric_code)
) ;
CREATE TABLE config_repositories
(
 id integer not null,
 url varchar(1023) not null,
 auth_token varchar(63) null,
 description varchar(1023) null,
 PRIMARY KEY(id)
) ;
INSERT INTO metadata (var_name,var_value)
 VALUES ('SchemaVersion',415);
INSERT INTO metadata (var_name,var_value)
 VALUES ('Syntax','DB2');
INSERT INTO metadata (var_name,var_value)
 VALUES ('IDataTableCreationCommand','CREATE TABLE idata_%d (item_id integer not null,idata_timestamp integer not null,idata_value varchar(255) null)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('IDataIndexCreationCommand_0','CREATE INDEX idx_idata_%d_id_timestamp ON idata_%d(item_id,idata_timestamp DESC)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('TDataTableCreationCommand_0','CREATE TABLE tdata_%d (item_id integer not null,tdata_timestamp integer not null,tdata_value ' || 'LONG VARCHAR' || ' null)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('TDataIndexCreationCommand_0','CREATE INDEX idx_tdata_%d ON tdata_%d(item_id,tdata_timestamp)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('LocationHistory','CREATE TABLE gps_history_%d (latitude varchar(20), longitude varchar(20), accuracy integer not null, start_timestamp integer not null, end_timestamp integer not null, PRIMARY KEY(start_timestamp))');
COMMIT;
