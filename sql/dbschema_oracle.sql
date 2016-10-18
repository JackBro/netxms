CREATE TABLE metadata
(
  var_name varchar(63) not null,
  var_value varchar(255) not null,
  PRIMARY KEY(var_name)
) ;
COMMENT ON TABLE metadata IS 'System meta data (DBMS type, schema version, etc.)';
COMMENT ON COLUMN metadata.var_name IS 'Variable name';
COMMENT ON COLUMN metadata.var_value IS 'Variable value';
CREATE TABLE config
(
  var_name varchar(63) not null,
  var_value varchar(2000) null,
  is_visible integer default 1 not null,
  need_server_restart integer default 0 not null,
  data_type char(1) default 'S' not null,
  is_public char(1) default 'N' not null,
  description varchar(255) null,
  possible_values clob null,
  PRIMARY KEY(var_name)
) ;
COMMENT ON TABLE config IS 'Server configuration';
COMMENT ON COLUMN config.var_name IS 'Parameter name';
COMMENT ON COLUMN config.var_value IS 'Value';
COMMENT ON COLUMN config.is_visible IS 'GUI visibility indicator';
COMMENT ON COLUMN config.need_server_restart IS 'Change take effect after server restart';
COMMENT ON COLUMN config.data_type IS 'Not used in current verion';
COMMENT ON COLUMN config.is_public IS 'No used in current version';
COMMENT ON COLUMN config.description IS 'Not used in current version';
COMMENT ON COLUMN config.possible_values IS 'Not used in current version';
CREATE TABLE config_clob
(
  var_name varchar(63) not null,
  var_value clob null,
  PRIMARY KEY(var_name)
) ;
COMMENT ON TABLE config_clob IS 'System configuration table for large data elements';
COMMENT ON COLUMN config_clob.var_name IS 'Parameter name';
COMMENT ON COLUMN config_clob.var_value IS 'Value';
CREATE TABLE users
(
  id integer not null,
  guid varchar(36) not null,
  name varchar(63) not null,
  password varchar(127) not null,
  system_access number(20) not null,
  flags integer not null,
  full_name varchar(127) null,
  description varchar(255) null,
  grace_logins integer not null,
  auth_method integer not null,
  cert_mapping_method integer not null,
  cert_mapping_data clob null,
  auth_failures integer not null,
  last_passwd_change integer not null,
  min_passwd_length integer not null,
  disabled_until integer not null,
  last_login integer not null,
  password_history clob null,
  xmpp_id varchar(127) null,
  ldap_dn clob null,
  ldap_unique_id varchar(64) null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE users IS 'System users';
COMMENT ON COLUMN users.id IS 'User id';
COMMENT ON COLUMN users.guid IS 'User guid';
COMMENT ON COLUMN users.name IS 'Login name';
COMMENT ON COLUMN users.password IS 'Hashed password';
COMMENT ON COLUMN users.system_access IS 'Bit-mask of system access rights';
COMMENT ON COLUMN users.flags IS 'Account flags (locked, password never expire etc.)';
COMMENT ON COLUMN users.full_name IS 'Full name';
COMMENT ON COLUMN users.description IS 'Description';
COMMENT ON COLUMN users.grace_logins IS '';
COMMENT ON COLUMN users.auth_method IS '';
COMMENT ON COLUMN users.cert_mapping_method IS '';
COMMENT ON COLUMN users.cert_mapping_data IS '';
COMMENT ON COLUMN users.auth_failures IS '';
COMMENT ON COLUMN users.last_passwd_change IS '';
COMMENT ON COLUMN users.min_passwd_length IS '';
COMMENT ON COLUMN users.disabled_until IS '';
COMMENT ON COLUMN users.last_login IS '';
COMMENT ON COLUMN users.password_history IS '';
COMMENT ON COLUMN users.xmpp_id IS '';
COMMENT ON COLUMN users.ldap_dn IS 'LDAP dn';
COMMENT ON COLUMN users.ldap_unique_id IS 'LDAP unique id if field set';
CREATE TABLE user_groups
(
  id integer not null,
  guid varchar(36) not null,
  name varchar(63) not null,
  system_access number(20) not null,
  flags integer not null,
  description varchar(255),
  ldap_dn clob null,
  ldap_unique_id varchar(64) null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE user_groups IS 'System user groups';
COMMENT ON COLUMN user_groups.id IS 'Group id';
COMMENT ON COLUMN user_groups.guid IS 'Group GUID';
COMMENT ON COLUMN user_groups.name IS 'Group name';
COMMENT ON COLUMN user_groups.system_access IS 'Bit-mask of system access rights';
COMMENT ON COLUMN user_groups.flags IS '';
COMMENT ON COLUMN user_groups.description IS 'Description';
COMMENT ON COLUMN user_groups.ldap_dn IS 'LDAP dn';
COMMENT ON COLUMN users.ldap_unique_id IS 'LDAP unique id if field set';
CREATE TABLE user_group_members
(
  group_id integer not null,
  user_id integer not null,
  PRIMARY KEY(group_id,user_id)
) ;
COMMENT ON TABLE user_group_members IS 'Users and group relationships';
COMMENT ON COLUMN user_group_members.group_id IS 'Group id from user_groups table';
COMMENT ON COLUMN user_group_members.user_id IS 'User id from users table';
CREATE TABLE user_profiles
(
  user_id integer not null,
  var_name varchar(255) not null,
  var_value clob not null,
  PRIMARY KEY(user_id,var_name)
) ;
COMMENT ON TABLE user_profiles IS 'User profiles';
COMMENT ON COLUMN user_profiles.user_id IS '';
COMMENT ON COLUMN user_profiles.var_name IS '';
COMMENT ON COLUMN user_profiles.var_value IS '';
CREATE TABLE userdb_custom_attributes
(
  object_id integer not null,
  attr_name varchar(255) not null,
  attr_value clob not null,
  PRIMARY KEY(object_id,attr_name)
) ;
COMMENT ON TABLE userdb_custom_attributes IS '';
COMMENT ON COLUMN userdb_custom_attributes.object_id IS '';
COMMENT ON COLUMN userdb_custom_attributes.attr_name IS '';
COMMENT ON COLUMN userdb_custom_attributes.attr_value IS '';
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
  comments clob null,
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
  maint_event_id number(20) not null,
  PRIMARY KEY(object_id)
) ;
COMMENT ON TABLE object_properties IS 'Object properties of NetObj and everything that is inherited from it(Dashboard, Interface, Node...)';
COMMENT ON COLUMN object_properties.object_id IS 'Object id';
COMMENT ON COLUMN object_properties.guid IS 'Object GUID';
COMMENT ON COLUMN object_properties.name IS 'Object name';
COMMENT ON COLUMN object_properties.status IS 'Object status(Unknown, Normal, Warning, Minor ...)';
COMMENT ON COLUMN object_properties.is_deleted IS 'Flag that defines if this object is scheduled for deletion';
COMMENT ON COLUMN object_properties.is_system IS 'Flag that defines if this object is the system object(DashboardRoot, ServiceRoot...)';
COMMENT ON COLUMN object_properties.last_modified IS 'Timestamp when this object was last modified';
COMMENT ON COLUMN object_properties.inherit_access_rights IS '';
COMMENT ON COLUMN object_properties.status_calc_alg IS '';
COMMENT ON COLUMN object_properties.status_prop_alg IS '';
COMMENT ON COLUMN object_properties.status_fixed_val IS '';
COMMENT ON COLUMN object_properties.status_shift IS '';
COMMENT ON COLUMN object_properties.status_translation IS '';
COMMENT ON COLUMN object_properties.status_single_threshold IS '';
COMMENT ON COLUMN object_properties.status_thresholds IS '';
COMMENT ON COLUMN object_properties.comments IS 'Comments';
COMMENT ON COLUMN object_properties.location_type IS 'Lacation type(Undefined, Manual, Automatic)';
COMMENT ON COLUMN object_properties.latitude IS 'Latitude value';
COMMENT ON COLUMN object_properties.longitude IS 'Longitude value';
COMMENT ON COLUMN object_properties.location_accuracy IS 'Received location accuracy';
COMMENT ON COLUMN object_properties.location_timestamp IS 'Last received location time';
COMMENT ON COLUMN object_properties.image IS '';
COMMENT ON COLUMN object_properties.submap_id IS '';
COMMENT ON COLUMN object_properties.country IS 'Object location country';
COMMENT ON COLUMN object_properties.city IS 'Object location city';
COMMENT ON COLUMN object_properties.street_address IS 'Object location address';
COMMENT ON COLUMN object_properties.postcode IS 'Object location postcode';
COMMENT ON COLUMN object_properties.maint_mode IS '';
COMMENT ON COLUMN object_properties.maint_event_id IS '';
CREATE TABLE object_custom_attributes
(
  object_id integer not null,
  attr_name varchar(127) not null,
  attr_value clob null,
  PRIMARY KEY(object_id,attr_name)
) ;
CREATE INDEX idx_ocattr_oid ON object_custom_attributes(object_id);
COMMENT ON TABLE object_custom_attributes IS 'Object custom attributes';
COMMENT ON COLUMN object_custom_attributes.object_id IS 'Object id from object_properties';
COMMENT ON COLUMN object_custom_attributes.attr_name IS 'Object attribute name';
COMMENT ON COLUMN object_custom_attributes.attr_value IS 'Object attribute value';
CREATE TABLE zones
(
  id integer not null,
  zone_guid integer not null,
  proxy_node integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE zones IS 'Zones';
COMMENT ON COLUMN zones.id IS 'Zone id from object_properties';
COMMENT ON COLUMN zones.zone_guid IS 'Zone GUID';
COMMENT ON COLUMN zones.proxy_node IS 'ID of proxy node for this zone';
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
COMMENT ON TABLE mobile_devices IS 'Mobile devices from object_properties';
COMMENT ON COLUMN mobile_devices.id IS 'Mobile device id';
COMMENT ON COLUMN mobile_devices.device_id IS 'Device ID(IMEI or ESN)';
COMMENT ON COLUMN mobile_devices.vendor IS 'Device vendor';
COMMENT ON COLUMN mobile_devices.model IS 'Device model';
COMMENT ON COLUMN mobile_devices.serial_number IS 'Serial number';
COMMENT ON COLUMN mobile_devices.os_name IS 'Operating system name';
COMMENT ON COLUMN mobile_devices.os_version IS 'Operation system version';
COMMENT ON COLUMN mobile_devices.user_id IS '';
COMMENT ON COLUMN mobile_devices.battery_level IS 'Battery charge level';
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
COMMENT ON TABLE access_points IS '';
COMMENT ON COLUMN access_points.id IS '';
COMMENT ON COLUMN access_points.node_id IS '';
COMMENT ON COLUMN access_points.mac_address IS '';
COMMENT ON COLUMN access_points.vendor IS '';
COMMENT ON COLUMN access_points.model IS '';
COMMENT ON COLUMN access_points.serial_number IS '';
COMMENT ON COLUMN access_points.ap_state IS '';
COMMENT ON COLUMN access_points.ap_index IS '';
CREATE TABLE racks
(
  id integer not null,
  height integer not null,
  top_bottom_num char(1) not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE racks IS 'Racks';
COMMENT ON COLUMN racks.id IS 'Rack id form object_properties';
COMMENT ON COLUMN racks.height IS '';
COMMENT ON COLUMN racks.top_bottom_num IS '';
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
COMMENT ON TABLE chassis IS 'Chassis';
COMMENT ON COLUMN chassis.id IS 'Chassis id form object_properties';
COMMENT ON COLUMN chassis.controller_id IS 'Id of node object providing management capabilities for this chassis';
COMMENT ON COLUMN chassis.flags IS 'Chassis options as bit flags';
COMMENT ON COLUMN chassis.rack_id IS 'Related rack object ID';
COMMENT ON COLUMN chassis.rack_image IS 'Image to be used in rack view';
COMMENT ON COLUMN chassis.rack_position IS 'Position in rack (in rack units)';
COMMENT ON COLUMN chassis.rack_height IS 'Height in rack (in rack units)';
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
  syslog_msg_count number(20) not null,
  snmp_trap_count number(20) not null,
  node_type integer not null,
  node_subtype varchar(127) null,
  ssh_login varchar(63) null,
  ssh_password varchar(63) null,
  ssh_proxy integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE nodes IS 'Nodes';
COMMENT ON COLUMN nodes.id IS 'Node id from object_properties';
COMMENT ON COLUMN nodes.primary_name IS '';
COMMENT ON COLUMN nodes.primary_ip IS '';
COMMENT ON COLUMN nodes.node_flags IS '';
COMMENT ON COLUMN nodes.runtime_flags IS '';
COMMENT ON COLUMN nodes.snmp_version IS '';
COMMENT ON COLUMN nodes.snmp_port IS '';
COMMENT ON COLUMN nodes.community IS '';
COMMENT ON COLUMN nodes.usm_auth_password IS '';
COMMENT ON COLUMN nodes.usm_priv_password IS '';
COMMENT ON COLUMN nodes.usm_methods IS '';
COMMENT ON COLUMN nodes.snmp_oid IS '';
COMMENT ON COLUMN nodes.auth_method IS '';
COMMENT ON COLUMN nodes.secret IS '';
COMMENT ON COLUMN nodes.agent_port IS '';
COMMENT ON COLUMN nodes.status_poll_type IS '';
COMMENT ON COLUMN nodes.agent_version IS '';
COMMENT ON COLUMN nodes.platform_name IS '';
COMMENT ON COLUMN nodes.poller_node_id IS '';
COMMENT ON COLUMN nodes.zone_guid IS '';
COMMENT ON COLUMN nodes.proxy_node IS '';
COMMENT ON COLUMN nodes.snmp_proxy IS '';
COMMENT ON COLUMN nodes.icmp_proxy IS '';
COMMENT ON COLUMN nodes.required_polls IS '';
COMMENT ON COLUMN nodes.uname IS '';
COMMENT ON COLUMN nodes.use_ifxtable IS '';
COMMENT ON COLUMN nodes.snmp_sys_name IS '';
COMMENT ON COLUMN nodes.snmp_sys_contact IS '';
COMMENT ON COLUMN nodes.snmp_sys_location IS '';
COMMENT ON COLUMN nodes.bridge_base_addr IS '';
COMMENT ON COLUMN nodes.down_since IS '';
COMMENT ON COLUMN nodes.boot_time IS '';
COMMENT ON COLUMN nodes.driver_name IS '';
COMMENT ON COLUMN nodes.rack_image IS '';
COMMENT ON COLUMN nodes.rack_position IS '';
COMMENT ON COLUMN nodes.rack_height IS '';
COMMENT ON COLUMN nodes.rack_id IS '';
COMMENT ON COLUMN nodes.chassis_id IS 'ID of chassis object this node belongs to';
COMMENT ON COLUMN nodes.agent_cache_mode IS '';
COMMENT ON COLUMN nodes.last_agent_comm_time IS '';
COMMENT ON COLUMN nodes.syslog_msg_count IS 'Total number of received syslog messages';
COMMENT ON COLUMN nodes.snmp_trap_count IS 'Total number of received SNMP traps';
CREATE TABLE clusters
(
  id integer not null,
  cluster_type integer not null,
  zone_guid integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE clusters IS 'Clusters';
COMMENT ON COLUMN clusters.id IS 'Cluster id form object_properties';
COMMENT ON COLUMN clusters.cluster_type IS 'Cluster type';
COMMENT ON COLUMN clusters.zone_guid IS 'Zone GUID form zones table';
CREATE TABLE cluster_members
(
  cluster_id integer not null,
  node_id integer not null,
  PRIMARY KEY(cluster_id,node_id)
) ;
COMMENT ON TABLE cluster_members IS 'Cluster members';
COMMENT ON COLUMN cluster_members.cluster_id IS 'Cluster id from clusters table';
COMMENT ON COLUMN cluster_members.node_id IS 'Node id form nodes table';
CREATE TABLE cluster_sync_subnets
(
  cluster_id integer not null,
  subnet_addr varchar(48) not null,
  subnet_mask integer not null,
  PRIMARY KEY(cluster_id,subnet_addr)
) ;
COMMENT ON TABLE cluster_sync_subnets IS '';
COMMENT ON COLUMN cluster_sync_subnets.cluster_id IS '';
COMMENT ON COLUMN cluster_sync_subnets.subnet_addr IS '';
COMMENT ON COLUMN cluster_sync_subnets.subnet_mask IS '';
CREATE TABLE cluster_resources
(
  cluster_id integer not null,
  resource_id integer not null,
  resource_name varchar(255),
  ip_addr varchar(48) not null,
  current_owner integer not null,
  PRIMARY KEY(cluster_id,resource_id)
) ;
COMMENT ON TABLE cluster_resources IS '';
COMMENT ON COLUMN cluster_resources.cluster_id IS '';
COMMENT ON COLUMN cluster_resources.resource_id IS '';
COMMENT ON COLUMN cluster_resources.resource_name IS '';
COMMENT ON COLUMN cluster_resources.ip_addr IS '';
COMMENT ON COLUMN cluster_resources.current_owner IS '';
CREATE TABLE subnets
(
  id integer not null,
  ip_addr varchar(48) not null,
  ip_netmask integer not null,
  zone_guid integer not null,
  synthetic_mask integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE subnets IS '';
CREATE TABLE interfaces
(
  id integer not null,
  node_id integer not null,
  flags integer not null,
  if_type integer not null,
  if_index integer not null,
  mtu integer not null,
  speed number(20) not null,
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
COMMENT ON TABLE interfaces IS '';
COMMENT ON COLUMN interfaces.id IS '';
COMMENT ON COLUMN interfaces.node_id IS '';
COMMENT ON COLUMN interfaces.flags IS '';
COMMENT ON COLUMN interfaces.if_type IS '';
COMMENT ON COLUMN interfaces.if_index IS '';
COMMENT ON COLUMN interfaces.mtu IS '';
COMMENT ON COLUMN interfaces.speed IS '';
COMMENT ON COLUMN interfaces.bridge_port IS '';
COMMENT ON COLUMN interfaces.phy_slot IS '';
COMMENT ON COLUMN interfaces.phy_port IS '';
COMMENT ON COLUMN interfaces.peer_node_id IS '';
COMMENT ON COLUMN interfaces.peer_if_id IS '';
COMMENT ON COLUMN interfaces.peer_proto IS '';
COMMENT ON COLUMN interfaces.mac_addr IS '';
COMMENT ON COLUMN interfaces.required_polls IS '';
COMMENT ON COLUMN interfaces.admin_state IS '';
COMMENT ON COLUMN interfaces.oper_state IS '';
COMMENT ON COLUMN interfaces.dot1x_pae_state IS '';
COMMENT ON COLUMN interfaces.dot1x_backend_state IS '';
COMMENT ON COLUMN interfaces.description IS '';
COMMENT ON COLUMN interfaces.alias IS '';
COMMENT ON COLUMN interfaces.iftable_suffix IS '';
CREATE TABLE interface_address_list
(
  iface_id integer not null,
  ip_addr varchar(48) not null,
  ip_netmask integer not null,
  PRIMARY KEY(iface_id,ip_addr)
) ;
COMMENT ON TABLE interface_address_list IS '';
COMMENT ON COLUMN interface_address_list.iface_id IS '';
COMMENT ON COLUMN interface_address_list.ip_addr IS '';
COMMENT ON COLUMN interface_address_list.ip_netmask IS '';
CREATE TABLE network_services
(
  id integer not null,
  node_id integer not null,
  service_type integer not null,
  ip_bind_addr varchar(48) not null,
  ip_proto integer not null,
  ip_port integer not null,
  check_request clob null,
  check_responce clob null,
  poller_node_id integer not null,
  required_polls integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE network_services IS '';
COMMENT ON COLUMN network_services.id IS '';
COMMENT ON COLUMN network_services.node_id IS '';
COMMENT ON COLUMN network_services.service_type IS '';
COMMENT ON COLUMN network_services.ip_bind_addr IS '';
COMMENT ON COLUMN network_services.ip_proto IS '';
COMMENT ON COLUMN network_services.ip_port IS '';
COMMENT ON COLUMN network_services.check_request IS '';
COMMENT ON COLUMN network_services.check_responce IS '';
COMMENT ON COLUMN network_services.poller_node_id IS '';
COMMENT ON COLUMN network_services.required_polls IS '';
CREATE TABLE vpn_connectors
(
  id integer not null,
  node_id integer not null,
  peer_gateway integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE vpn_connectors IS '';
COMMENT ON COLUMN vpn_connectors.id IS '';
COMMENT ON COLUMN vpn_connectors.node_id IS '';
COMMENT ON COLUMN vpn_connectors.peer_gateway IS '';
CREATE TABLE vpn_connector_networks
(
  vpn_id integer not null,
  network_type integer not null,
  ip_addr varchar(48) not null,
  ip_netmask integer not null,
  PRIMARY KEY(vpn_id,ip_addr)
) ;
COMMENT ON TABLE vpn_connector_networks IS '';
COMMENT ON COLUMN vpn_connector_networks.vpn_id IS '';
COMMENT ON COLUMN vpn_connector_networks.network_type IS '';
COMMENT ON COLUMN vpn_connector_networks.ip_addr IS '';
COMMENT ON COLUMN vpn_connector_networks.ip_netmask IS '';
CREATE TABLE object_containers
(
  id integer not null,
  object_class integer not null,
  flags integer not null,
  auto_bind_filter clob null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE object_containers IS '';
COMMENT ON COLUMN object_containers.id IS '';
COMMENT ON COLUMN object_containers.object_class IS '';
COMMENT ON COLUMN object_containers.flags IS '';
COMMENT ON COLUMN object_containers.auto_bind_filter IS '';
CREATE TABLE conditions
(
  id integer not null,
  activation_event integer not null,
  deactivation_event integer not null,
  source_object integer not null,
  active_status integer not null,
  inactive_status integer not null,
  script clob not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE conditions IS '';
COMMENT ON COLUMN conditions.id IS '';
COMMENT ON COLUMN conditions.activation_event IS '';
COMMENT ON COLUMN conditions.deactivation_event IS '';
COMMENT ON COLUMN conditions.source_object IS '';
COMMENT ON COLUMN conditions.active_status IS '';
COMMENT ON COLUMN conditions.inactive_status IS '';
COMMENT ON COLUMN conditions.script IS '';
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
COMMENT ON TABLE cond_dci_map IS '';
COMMENT ON COLUMN cond_dci_map.condition_id IS '';
COMMENT ON COLUMN cond_dci_map.sequence_number IS '';
COMMENT ON COLUMN cond_dci_map.dci_id IS '';
COMMENT ON COLUMN cond_dci_map.node_id IS '';
COMMENT ON COLUMN cond_dci_map.dci_func IS '';
COMMENT ON COLUMN cond_dci_map.num_polls IS '';
CREATE TABLE templates
(
  id integer not null,
  version integer not null,
  flags integer not null,
  apply_filter clob null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE templates IS '';
COMMENT ON COLUMN templates.id IS '';
COMMENT ON COLUMN templates.version IS '';
COMMENT ON COLUMN templates.flags IS '';
COMMENT ON COLUMN templates.apply_filter IS '';
CREATE TABLE dct_node_map
(
  template_id integer not null,
  node_id integer not null,
  PRIMARY KEY(template_id,node_id)
) ;
COMMENT ON TABLE dct_node_map IS '';
COMMENT ON COLUMN dct_node_map.template_id IS '';
COMMENT ON COLUMN dct_node_map.node_id IS '';
CREATE TABLE nsmap
(
  subnet_id integer not null,
  node_id integer not null,
  PRIMARY KEY(subnet_id,node_id)
) ;
COMMENT ON TABLE nsmap IS '';
COMMENT ON COLUMN nsmap.subnet_id IS '';
COMMENT ON COLUMN nsmap.node_id IS '';
CREATE TABLE container_members
(
  container_id integer not null,
  object_id integer not null,
  PRIMARY KEY(container_id,object_id)
) ;
COMMENT ON TABLE container_members IS '';
COMMENT ON COLUMN container_members.container_id IS '';
COMMENT ON COLUMN container_members.object_id IS '';
CREATE TABLE acl
(
  object_id integer not null,
  user_id integer not null,
  access_rights integer not null,
  PRIMARY KEY(object_id,user_id)
) ;
COMMENT ON TABLE acl IS '';
COMMENT ON COLUMN acl.object_id IS '';
COMMENT ON COLUMN acl.user_id IS '';
COMMENT ON COLUMN acl.access_rights IS '';
CREATE TABLE trusted_nodes
(
  source_object_id integer not null,
  target_node_id integer not null,
  PRIMARY KEY(source_object_id,target_node_id)
) ;
COMMENT ON TABLE trusted_nodes IS '';
COMMENT ON COLUMN trusted_nodes.source_object_id IS '';
COMMENT ON COLUMN trusted_nodes.target_node_id IS '';
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
  transformation clob,
  instance varchar(255) null,
  system_tag varchar(255) null,
  resource_id integer not null,
  proxy_node integer not null,
  base_units integer not null,
  unit_multiplier integer not null,
  custom_units_name varchar(63) null,
  perftab_settings clob null,
  instd_method integer not null,
  instd_data varchar(255) null,
  instd_filter clob null,
  samples integer not null,
  comments clob null,
  PRIMARY KEY(item_id)
) ;
CREATE INDEX idx_items_node_id ON items(node_id);
COMMENT ON TABLE items IS '';
COMMENT ON COLUMN items.item_id IS '';
COMMENT ON COLUMN items.node_id IS '';
COMMENT ON COLUMN items.template_id IS '';
COMMENT ON COLUMN items.template_item_id IS '';
COMMENT ON COLUMN items.guid IS '';
COMMENT ON COLUMN items.name IS '';
COMMENT ON COLUMN items.description IS '';
COMMENT ON COLUMN items.flags IS '';
COMMENT ON COLUMN items.source IS '';
COMMENT ON COLUMN items.snmp_port IS '';
COMMENT ON COLUMN items.datatype IS '';
COMMENT ON COLUMN items.polling_interval IS '';
COMMENT ON COLUMN items.retention_time IS '';
COMMENT ON COLUMN items.status IS '';
COMMENT ON COLUMN items.snmp_raw_value_type IS '';
COMMENT ON COLUMN items.delta_calculation IS '';
COMMENT ON COLUMN items.transformation IS '';
COMMENT ON COLUMN items.instance IS '';
COMMENT ON COLUMN items.system_tag IS '';
COMMENT ON COLUMN items.resource_id IS '';
COMMENT ON COLUMN items.proxy_node IS '';
COMMENT ON COLUMN items.base_units IS '';
COMMENT ON COLUMN items.unit_multiplier IS '';
COMMENT ON COLUMN items.custom_units_name IS '';
COMMENT ON COLUMN items.perftab_settings IS '';
COMMENT ON COLUMN items.instd_method IS '';
COMMENT ON COLUMN items.instd_data IS '';
COMMENT ON COLUMN items.instd_filter IS '';
COMMENT ON COLUMN items.samples IS '';
COMMENT ON COLUMN items.comments IS '';
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
  perftab_settings clob null,
  transformation_script clob null,
  comments clob null,
  PRIMARY KEY(item_id)
) ;
CREATE INDEX idx_dc_tables_node_id ON dc_tables(node_id);
COMMENT ON TABLE dc_tables IS '';
COMMENT ON COLUMN dc_tables.item_id IS '';
COMMENT ON COLUMN dc_tables.node_id IS '';
COMMENT ON COLUMN dc_tables.template_id IS '';
COMMENT ON COLUMN dc_tables.template_item_id IS '';
COMMENT ON COLUMN dc_tables.guid IS '';
COMMENT ON COLUMN dc_tables.name IS '';
COMMENT ON COLUMN dc_tables.description IS '';
COMMENT ON COLUMN dc_tables.flags IS '';
COMMENT ON COLUMN dc_tables.source IS '';
COMMENT ON COLUMN dc_tables.snmp_port IS '';
COMMENT ON COLUMN dc_tables.polling_interval IS '';
COMMENT ON COLUMN dc_tables.retention_time IS '';
COMMENT ON COLUMN dc_tables.status IS '';
COMMENT ON COLUMN dc_tables.system_tag IS '';
COMMENT ON COLUMN dc_tables.resource_id IS '';
COMMENT ON COLUMN dc_tables.proxy_node IS '';
COMMENT ON COLUMN dc_tables.perftab_settings IS '';
COMMENT ON COLUMN dc_tables.transformation_script IS '';
COMMENT ON COLUMN dc_tables.comments IS '';
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
COMMENT ON TABLE dc_table_columns IS '';
COMMENT ON COLUMN dc_table_columns.table_id IS '';
COMMENT ON COLUMN dc_table_columns.sequence_number IS '';
COMMENT ON COLUMN dc_table_columns.column_name IS '';
COMMENT ON COLUMN dc_table_columns.snmp_oid IS '';
COMMENT ON COLUMN dc_table_columns.flags IS '';
COMMENT ON COLUMN dc_table_columns.display_name IS '';
CREATE TABLE dct_column_names
(
  column_id integer not null,
  column_name varchar(63) not null,
  PRIMARY KEY(column_id)
) ;
COMMENT ON TABLE dct_column_names IS '';
COMMENT ON COLUMN dct_column_names.column_id IS '';
COMMENT ON COLUMN dct_column_names.column_name IS '';
CREATE TABLE dct_thresholds
(
  id integer not null,
  table_id integer not null,
  sequence_number integer not null,
  activation_event integer not null,
  deactivation_event integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE dct_thresholds IS '';
COMMENT ON COLUMN dct_thresholds.id IS '';
COMMENT ON COLUMN dct_thresholds.table_id IS '';
COMMENT ON COLUMN dct_thresholds.sequence_number IS '';
COMMENT ON COLUMN dct_thresholds.activation_event IS '';
COMMENT ON COLUMN dct_thresholds.deactivation_event IS '';
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
COMMENT ON TABLE dct_threshold_conditions IS '';
COMMENT ON COLUMN dct_threshold_conditions.threshold_id IS '';
COMMENT ON COLUMN dct_threshold_conditions.group_id IS '';
COMMENT ON COLUMN dct_threshold_conditions.sequence_number IS '';
COMMENT ON COLUMN dct_threshold_conditions.column_name IS '';
COMMENT ON COLUMN dct_threshold_conditions.check_operation IS '';
COMMENT ON COLUMN dct_threshold_conditions.check_value IS '';
CREATE TABLE dci_schedules
(
  schedule_id integer not null,
  item_id integer not null,
  schedule varchar(255) null,
  PRIMARY KEY(item_id,schedule_id)
) ;
COMMENT ON TABLE dci_schedules IS '';
COMMENT ON COLUMN dci_schedules.schedule_id IS '';
COMMENT ON COLUMN dci_schedules.item_id IS '';
COMMENT ON COLUMN dci_schedules.schedule IS '';
CREATE TABLE raw_dci_values
(
  item_id integer not null,
  raw_value varchar(255) null,
  transformed_value varchar(255) null,
  last_poll_time integer not null,
  PRIMARY KEY(item_id)
) ;
COMMENT ON TABLE raw_dci_values IS '';
COMMENT ON COLUMN raw_dci_values.item_id IS '';
COMMENT ON COLUMN raw_dci_values.raw_value IS '';
COMMENT ON COLUMN raw_dci_values.transformed_value IS '';
COMMENT ON COLUMN raw_dci_values.last_poll_time IS '';
CREATE TABLE event_cfg
(
  event_code integer not null,
  event_name varchar(63) not null,
  guid varchar(36) not null,
  severity integer not null,
  flags integer not null,
  message varchar(2000) null,
  description clob null,
  PRIMARY KEY(event_code)
) ;
COMMENT ON TABLE event_cfg IS 'Event templates';
COMMENT ON COLUMN event_cfg.event_code IS 'Event code (unique within system)';
COMMENT ON COLUMN event_cfg.event_name IS 'Event name';
COMMENT ON COLUMN event_cfg.guid IS 'Event template GUID';
COMMENT ON COLUMN event_cfg.severity IS 'Severity';
COMMENT ON COLUMN event_cfg.flags IS 'Flags';
COMMENT ON COLUMN event_cfg.message IS 'Message template';
COMMENT ON COLUMN event_cfg.description IS 'Event description';
CREATE TABLE event_log
(
  event_id number(20) not null,
  event_code integer not null,
  event_timestamp integer not null,
  event_source integer not null,
  dci_id integer not null,
  event_severity integer not null,
  event_message varchar(2000) null,
  root_event_id number(20) not null,
  user_tag varchar(63) null,
  PRIMARY KEY(event_id)
) ;
CREATE INDEX idx_event_log_event_timestamp ON event_log(event_timestamp);
CREATE INDEX idx_event_log_source ON event_log(event_source);
CREATE OR REPLACE FUNCTION zero_to_null(id NUMBER)
RETURN NUMBER
DETERMINISTIC
AS BEGIN
   IF id > 0 THEN
      RETURN id;
   ELSE
      RETURN NULL;
   END IF;
END;
/
CREATE INDEX idx_event_log_root_id ON event_log(zero_to_null(root_event_id));
COMMENT ON TABLE event_log IS '';
COMMENT ON COLUMN event_log.event_id IS '';
COMMENT ON COLUMN event_log.event_code IS '';
COMMENT ON COLUMN event_log.event_timestamp IS '';
COMMENT ON COLUMN event_log.event_source IS '';
COMMENT ON COLUMN event_log.dci_id IS '';
COMMENT ON COLUMN event_log.event_severity IS '';
COMMENT ON COLUMN event_log.event_message IS '';
COMMENT ON COLUMN event_log.root_event_id IS '';
COMMENT ON COLUMN event_log.user_tag IS '';
CREATE TABLE actions
(
  action_id integer not null,
  action_name varchar(63) not null,
  action_type integer not null,
  is_disabled integer not null,
  rcpt_addr varchar(255) null,
  email_subject varchar(255) null,
  action_data clob null,
  PRIMARY KEY(action_id)
) ;
COMMENT ON TABLE actions IS '';
COMMENT ON COLUMN actions.action_id IS '';
COMMENT ON COLUMN actions.action_name IS '';
COMMENT ON COLUMN actions.action_type IS '';
COMMENT ON COLUMN actions.is_disabled IS '';
COMMENT ON COLUMN actions.rcpt_addr IS '';
COMMENT ON COLUMN actions.email_subject IS '';
COMMENT ON COLUMN actions.action_data IS '';
CREATE TABLE event_groups
(
  id integer not null,
  name varchar(63) not null,
  description varchar(255) not null,
  range_start integer not null,
  range_end integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE event_groups IS '';
COMMENT ON COLUMN event_groups.id IS '';
COMMENT ON COLUMN event_groups.name IS '';
COMMENT ON COLUMN event_groups.description IS '';
COMMENT ON COLUMN event_groups.range_start IS '';
COMMENT ON COLUMN event_groups.range_end IS '';
CREATE TABLE event_group_members
(
  group_id integer not null,
  event_code integer not null,
  PRIMARY KEY(group_id,event_code)
) ;
COMMENT ON TABLE event_group_members IS '';
COMMENT ON COLUMN event_group_members.group_id IS '';
COMMENT ON COLUMN event_group_members.event_code IS '';
CREATE TABLE event_policy
(
  rule_id integer not null,
  rule_guid varchar(36) not null,
  flags integer not null,
  comments clob null,
  script clob null,
  alarm_message varchar(2000) null,
  alarm_severity integer not null,
  alarm_key varchar(255) null,
  alarm_timeout integer not null,
  alarm_timeout_event integer not null,
  situation_id integer not null,
  situation_instance varchar(255) null,
  PRIMARY KEY(rule_id)
) ;
COMMENT ON TABLE event_policy IS '';
COMMENT ON COLUMN event_policy.rule_id IS '';
COMMENT ON COLUMN event_policy.rule_guid IS '';
COMMENT ON COLUMN event_policy.flags IS '';
COMMENT ON COLUMN event_policy.comments IS '';
COMMENT ON COLUMN event_policy.script IS '';
COMMENT ON COLUMN event_policy.alarm_message IS '';
COMMENT ON COLUMN event_policy.alarm_severity IS '';
COMMENT ON COLUMN event_policy.alarm_key IS '';
COMMENT ON COLUMN event_policy.alarm_timeout IS '';
COMMENT ON COLUMN event_policy.alarm_timeout_event IS '';
COMMENT ON COLUMN event_policy.situation_id IS '';
COMMENT ON COLUMN event_policy.situation_instance IS '';
CREATE TABLE policy_source_list
(
  rule_id integer not null,
  object_id integer not null,
  PRIMARY KEY(rule_id,object_id)
) ;
COMMENT ON TABLE policy_source_list IS '';
COMMENT ON COLUMN policy_source_list.rule_id IS '';
COMMENT ON COLUMN policy_source_list.object_id IS '';
CREATE TABLE policy_event_list
(
  rule_id integer not null,
  event_code integer not null,
  PRIMARY KEY(rule_id,event_code)
) ;
COMMENT ON TABLE policy_event_list IS '';
COMMENT ON COLUMN policy_event_list.rule_id IS '';
COMMENT ON COLUMN policy_event_list.event_code IS '';
CREATE TABLE policy_action_list
(
  rule_id integer not null,
  action_id integer not null,
  PRIMARY KEY(rule_id,action_id)
) ;
COMMENT ON TABLE policy_action_list IS '';
COMMENT ON COLUMN policy_action_list.rule_id IS '';
COMMENT ON COLUMN policy_action_list.action_id IS '';
CREATE TABLE policy_situation_attr_list
(
  rule_id integer not null,
  situation_id integer not null,
  attr_name varchar(255) not null,
  attr_value varchar(255) null,
  PRIMARY KEY(rule_id,situation_id,attr_name)
) ;
COMMENT ON TABLE policy_situation_attr_list IS '';
COMMENT ON COLUMN policy_situation_attr_list.rule_id IS '';
COMMENT ON COLUMN policy_situation_attr_list.situation_id IS '';
COMMENT ON COLUMN policy_situation_attr_list.attr_name IS '';
COMMENT ON COLUMN policy_situation_attr_list.attr_value IS '';
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
  script clob null,
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
COMMENT ON TABLE thresholds IS '';
COMMENT ON COLUMN thresholds.threshold_id IS '';
COMMENT ON COLUMN thresholds.item_id IS '';
COMMENT ON COLUMN thresholds.sequence_number IS '';
COMMENT ON COLUMN thresholds.fire_value IS '';
COMMENT ON COLUMN thresholds.rearm_value IS '';
COMMENT ON COLUMN thresholds.check_function IS '';
COMMENT ON COLUMN thresholds.check_operation IS '';
COMMENT ON COLUMN thresholds.sample_count IS '';
COMMENT ON COLUMN thresholds.script IS '';
COMMENT ON COLUMN thresholds.event_code IS '';
COMMENT ON COLUMN thresholds.rearm_event_code IS '';
COMMENT ON COLUMN thresholds.repeat_interval IS '';
COMMENT ON COLUMN thresholds.current_state IS '';
COMMENT ON COLUMN thresholds.current_severity IS '';
COMMENT ON COLUMN thresholds.match_count IS '';
COMMENT ON COLUMN thresholds.last_event_timestamp IS '';
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
  source_event_id number(20) not null,
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
COMMENT ON TABLE alarms IS '';
COMMENT ON COLUMN alarms.alarm_id IS '';
COMMENT ON COLUMN alarms.alarm_state IS '';
COMMENT ON COLUMN alarms.hd_state IS '';
COMMENT ON COLUMN alarms.hd_ref IS '';
COMMENT ON COLUMN alarms.creation_time IS '';
COMMENT ON COLUMN alarms.last_change_time IS '';
COMMENT ON COLUMN alarms.source_object_id IS '';
COMMENT ON COLUMN alarms.source_event_code IS '';
COMMENT ON COLUMN alarms.source_event_id IS '';
COMMENT ON COLUMN alarms.dci_id IS '';
COMMENT ON COLUMN alarms.message IS '';
COMMENT ON COLUMN alarms.original_severity IS '';
COMMENT ON COLUMN alarms.current_severity IS '';
COMMENT ON COLUMN alarms.repeat_count IS '';
COMMENT ON COLUMN alarms.alarm_key IS '';
COMMENT ON COLUMN alarms.ack_by IS '';
COMMENT ON COLUMN alarms.resolved_by IS '';
COMMENT ON COLUMN alarms.term_by IS '';
COMMENT ON COLUMN alarms.timeout IS '';
COMMENT ON COLUMN alarms.timeout_event IS '';
COMMENT ON COLUMN alarms.ack_timeout IS '';
CREATE TABLE alarm_notes
(
  note_id integer not null,
  alarm_id integer not null,
  change_time integer not null,
  user_id integer not null,
  note_text clob null,
  PRIMARY KEY(note_id)
) ;
CREATE INDEX idx_alarm_notes_alarm_id ON alarm_notes(alarm_id);
COMMENT ON TABLE alarm_notes IS '';
COMMENT ON COLUMN alarm_notes.note_id IS '';
COMMENT ON COLUMN alarm_notes.alarm_id IS '';
COMMENT ON COLUMN alarm_notes.change_time IS '';
COMMENT ON COLUMN alarm_notes.user_id IS '';
COMMENT ON COLUMN alarm_notes.note_text IS '';
CREATE TABLE alarm_events
(
  alarm_id integer not null,
  event_id number(20) not null,
  event_code integer not null,
  event_name varchar(63) null,
  severity integer not null,
  source_object_id integer not null,
  event_timestamp integer not null,
  message varchar(2000) null,
  PRIMARY KEY(alarm_id,event_id)
) ;
CREATE INDEX idx_alarm_events_alarm_id ON alarm_events(alarm_id);
COMMENT ON TABLE alarm_events IS '';
COMMENT ON COLUMN alarm_events.alarm_id IS '';
COMMENT ON COLUMN alarm_events.event_id IS '';
COMMENT ON COLUMN alarm_events.event_code IS '';
COMMENT ON COLUMN alarm_events.event_name IS '';
COMMENT ON COLUMN alarm_events.severity IS '';
COMMENT ON COLUMN alarm_events.source_object_id IS '';
COMMENT ON COLUMN alarm_events.event_timestamp IS '';
COMMENT ON COLUMN alarm_events.message IS '';
CREATE TABLE snmp_trap_cfg
(
  trap_id integer not null,
  snmp_oid varchar(255),
  event_code integer not null,
  user_tag varchar(63),
  description varchar(255),
  PRIMARY KEY(trap_id)
) ;
COMMENT ON TABLE snmp_trap_cfg IS '';
COMMENT ON COLUMN snmp_trap_cfg.trap_id IS '';
COMMENT ON COLUMN snmp_trap_cfg.snmp_oid IS '';
COMMENT ON COLUMN snmp_trap_cfg.event_code IS '';
COMMENT ON COLUMN snmp_trap_cfg.user_tag IS '';
COMMENT ON COLUMN snmp_trap_cfg.description IS '';
CREATE TABLE snmp_trap_pmap
(
  trap_id integer not null,
  parameter integer not null,
  flags integer not null,
  snmp_oid varchar(255) null,
  description varchar(255) null,
  PRIMARY KEY(trap_id,parameter)
) ;
COMMENT ON TABLE snmp_trap_pmap IS '';
COMMENT ON COLUMN snmp_trap_pmap.trap_id IS '';
COMMENT ON COLUMN snmp_trap_pmap.parameter IS '';
COMMENT ON COLUMN snmp_trap_pmap.flags IS '';
COMMENT ON COLUMN snmp_trap_pmap.snmp_oid IS '';
COMMENT ON COLUMN snmp_trap_pmap.description IS '';
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
COMMENT ON TABLE agent_pkg IS '';
COMMENT ON COLUMN agent_pkg.pkg_id IS '';
COMMENT ON COLUMN agent_pkg.pkg_name IS '';
COMMENT ON COLUMN agent_pkg.version IS '';
COMMENT ON COLUMN agent_pkg.platform IS '';
COMMENT ON COLUMN agent_pkg.pkg_file IS '';
COMMENT ON COLUMN agent_pkg.description IS '';
CREATE TABLE object_tools
(
  tool_id integer not null,
  guid varchar(36) not null,
  tool_name varchar(255) null,
  tool_type integer not null,
  tool_data clob null,
  description varchar(255) null,
  flags integer not null,
  tool_filter clob null,
  confirmation_text varchar(255) null,
  command_name varchar(255) null,
  command_short_name varchar(31) null,
  icon clob null,
  PRIMARY KEY(tool_id)
) ;
COMMENT ON TABLE object_tools IS '';
COMMENT ON COLUMN object_tools.tool_id IS '';
COMMENT ON COLUMN object_tools.guid IS '';
COMMENT ON COLUMN object_tools.tool_name IS '';
COMMENT ON COLUMN object_tools.tool_type IS '';
COMMENT ON COLUMN object_tools.tool_data IS '';
COMMENT ON COLUMN object_tools.description IS '';
COMMENT ON COLUMN object_tools.flags IS '';
COMMENT ON COLUMN object_tools.tool_filter IS '';
COMMENT ON COLUMN object_tools.confirmation_text IS '';
COMMENT ON COLUMN object_tools.command_name IS '';
COMMENT ON COLUMN object_tools.command_short_name IS '';
COMMENT ON COLUMN object_tools.icon IS '';
CREATE TABLE object_tools_acl
(
  tool_id integer not null,
  user_id integer not null,
  PRIMARY KEY(tool_id,user_id)
) ;
COMMENT ON TABLE object_tools_acl IS '';
COMMENT ON COLUMN object_tools_acl.tool_id IS '';
COMMENT ON COLUMN object_tools_acl.user_id IS '';
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
COMMENT ON TABLE object_tools_table_columns IS '';
COMMENT ON COLUMN object_tools_table_columns.tool_id IS '';
COMMENT ON COLUMN object_tools_table_columns.col_number IS '';
COMMENT ON COLUMN object_tools_table_columns.col_name IS '';
COMMENT ON COLUMN object_tools_table_columns.col_oid IS '';
COMMENT ON COLUMN object_tools_table_columns.col_format IS '';
COMMENT ON COLUMN object_tools_table_columns.col_substr IS '';
CREATE TABLE object_tools_input_fields
(
  tool_id integer not null,
  name varchar(31) not null,
  input_type char(1) not null,
  display_name varchar(127) null,
  sequence_num integer not null,
  config clob null,
  PRIMARY KEY(tool_id,name)
) ;
COMMENT ON TABLE object_tools_input_fields IS '';
COMMENT ON COLUMN object_tools_input_fields.tool_id IS '';
COMMENT ON COLUMN object_tools_input_fields.name IS '';
COMMENT ON COLUMN object_tools_input_fields.input_type IS '';
COMMENT ON COLUMN object_tools_input_fields.display_name IS '';
COMMENT ON COLUMN object_tools_input_fields.sequence_num IS '';
COMMENT ON COLUMN object_tools_input_fields.config IS '';
CREATE TABLE syslog
(
  msg_id number(20) not null,
  msg_timestamp integer not null,
  facility integer not null,
  severity integer not null,
  source_object_id integer not null,
  hostname varchar(127) null,
  msg_tag varchar(32) null,
  msg_text clob null,
  PRIMARY KEY(msg_id)
) ;
CREATE INDEX idx_syslog_msg_timestamp ON syslog(msg_timestamp);
COMMENT ON TABLE syslog IS '';
COMMENT ON COLUMN syslog.msg_id IS '';
COMMENT ON COLUMN syslog.msg_timestamp IS '';
COMMENT ON COLUMN syslog.facility IS '';
COMMENT ON COLUMN syslog.severity IS '';
COMMENT ON COLUMN syslog.source_object_id IS '';
COMMENT ON COLUMN syslog.hostname IS '';
COMMENT ON COLUMN syslog.msg_tag IS '';
COMMENT ON COLUMN syslog.msg_text IS '';
CREATE TABLE script_library
(
  script_id integer not null,
  script_name varchar(255) not null,
  script_code clob null,
  PRIMARY KEY(script_id)
) ;
COMMENT ON TABLE script_library IS '';
COMMENT ON COLUMN script_library.script_id IS '';
COMMENT ON COLUMN script_library.script_name IS '';
COMMENT ON COLUMN script_library.script_code IS '';
CREATE TABLE snmp_trap_log
(
  trap_id number(20) not null,
  trap_timestamp integer not null,
  ip_addr varchar(48) not null,
  object_id integer not null,
  trap_oid varchar(255) not null,
  trap_varlist clob null,
  PRIMARY KEY(trap_id)
) ;
CREATE INDEX idx_snmp_trap_log_tt ON snmp_trap_log(trap_timestamp);
COMMENT ON TABLE snmp_trap_log IS '';
COMMENT ON COLUMN snmp_trap_log.trap_id IS '';
COMMENT ON COLUMN snmp_trap_log.trap_timestamp IS '';
COMMENT ON COLUMN snmp_trap_log.ip_addr IS '';
COMMENT ON COLUMN snmp_trap_log.object_id IS '';
COMMENT ON COLUMN snmp_trap_log.trap_oid IS '';
COMMENT ON COLUMN snmp_trap_log.trap_varlist IS '';
CREATE TABLE agent_configs
(
  config_id integer not null,
  config_name varchar(255) not null,
  config_file clob not null,
  config_filter clob not null,
  sequence_number integer not null,
  PRIMARY KEY(config_id)
) ;
COMMENT ON TABLE agent_configs IS '';
COMMENT ON COLUMN agent_configs.config_id IS '';
COMMENT ON COLUMN agent_configs.config_name IS '';
COMMENT ON COLUMN agent_configs.config_file IS '';
COMMENT ON COLUMN agent_configs.config_filter IS '';
COMMENT ON COLUMN agent_configs.sequence_number IS '';
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
COMMENT ON TABLE address_lists IS '';
COMMENT ON COLUMN address_lists.list_type IS '';
COMMENT ON COLUMN address_lists.community_id IS '';
COMMENT ON COLUMN address_lists.addr_type IS '';
COMMENT ON COLUMN address_lists.addr1 IS '';
COMMENT ON COLUMN address_lists.addr2 IS '';
CREATE TABLE graphs
(
  graph_id integer not null,
  owner_id integer not null,
  flags integer not null,
  name varchar(255) not null,
  config clob null,
  filters clob null,
  PRIMARY KEY(graph_id)
) ;
COMMENT ON TABLE graphs IS '';
COMMENT ON COLUMN graphs.graph_id IS '';
COMMENT ON COLUMN graphs.owner_id IS '';
COMMENT ON COLUMN graphs.flags IS '';
COMMENT ON COLUMN graphs.name IS '';
COMMENT ON COLUMN graphs.config IS '';
COMMENT ON COLUMN graphs.filters IS '';
CREATE TABLE graph_acl
(
  graph_id integer not null,
  user_id integer not null,
  user_rights integer not null,
  PRIMARY KEY(graph_id,user_id)
) ;
COMMENT ON TABLE graph_acl IS '';
COMMENT ON COLUMN graph_acl.graph_id IS '';
COMMENT ON COLUMN graph_acl.user_id IS '';
COMMENT ON COLUMN graph_acl.user_rights IS '';
CREATE TABLE certificates
(
  cert_id integer not null,
  cert_type integer not null,
  cert_data clob not null,
  subject clob not null,
  comments clob not null,
  PRIMARY KEY(cert_id)
) ;
COMMENT ON TABLE certificates IS '';
COMMENT ON COLUMN certificates.cert_id IS '';
COMMENT ON COLUMN certificates.cert_type IS '';
COMMENT ON COLUMN certificates.cert_data IS '';
COMMENT ON COLUMN certificates.subject IS '';
COMMENT ON COLUMN certificates.comments IS '';
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
  message clob null,
  PRIMARY KEY(record_id)
) ;
COMMENT ON TABLE audit_log IS '';
COMMENT ON COLUMN audit_log.record_id IS '';
COMMENT ON COLUMN audit_log.timestamp IS '';
COMMENT ON COLUMN audit_log.subsystem IS '';
COMMENT ON COLUMN audit_log.success IS '';
COMMENT ON COLUMN audit_log.user_id IS '';
COMMENT ON COLUMN audit_log.workstation IS '';
COMMENT ON COLUMN audit_log.session_id IS '';
COMMENT ON COLUMN audit_log.object_id IS '';
COMMENT ON COLUMN audit_log.message IS '';
CREATE TABLE situations
(
  id integer not null,
  name varchar(127) not null,
  comments clob not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE situations IS '';
COMMENT ON COLUMN situations.id IS '';
COMMENT ON COLUMN situations.name IS '';
COMMENT ON COLUMN situations.comments IS '';
CREATE TABLE snmp_communities
(
  id integer not null,
  community varchar(255) null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE snmp_communities IS '';
COMMENT ON COLUMN snmp_communities.id IS '';
COMMENT ON COLUMN snmp_communities.community IS '';
CREATE TABLE ap_common
(
  id integer not null,
  policy_type integer not null,
  version integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE ap_common IS 'Agent policies common attributes';
COMMENT ON COLUMN ap_common.id IS 'Unique policy identifier';
COMMENT ON COLUMN ap_common.policy_type IS 'Policy type';
COMMENT ON COLUMN ap_common.version IS 'Policy version';
CREATE TABLE ap_bindings
(
  policy_id integer not null,
  node_id integer not null,
  PRIMARY KEY(policy_id,node_id)
) ;
COMMENT ON TABLE ap_bindings IS 'Agent policies to node binding';
COMMENT ON COLUMN ap_bindings.policy_id IS 'Unique policy identifier';
COMMENT ON COLUMN ap_bindings.node_id IS 'Unique node identifier';
CREATE TABLE ap_config_files
(
  policy_id integer not null,
  file_content clob null,
  PRIMARY KEY(policy_id)
) ;
COMMENT ON TABLE ap_config_files IS 'Agent policies configuration files';
COMMENT ON COLUMN ap_config_files.policy_id IS 'Unique policy identifier';
COMMENT ON COLUMN ap_config_files.file_content IS 'Policy file content';
CREATE TABLE ap_log_parser
(
  policy_id integer not null,
  file_content clob null,
  PRIMARY KEY(policy_id)
) ;
COMMENT ON TABLE ap_log_parser IS 'Agent policies log parser files';
COMMENT ON COLUMN ap_log_parser.policy_id IS 'Unique policy identifier';
COMMENT ON COLUMN ap_log_parser.file_content IS 'Log parser policy file content';
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
COMMENT ON TABLE usm_credentials IS 'Default SNMP v3 USM credentials';
COMMENT ON COLUMN usm_credentials.id IS 'SNMP v3 USM credential unique identifier';
COMMENT ON COLUMN usm_credentials.user_name IS 'SNMP v3 USM username';
COMMENT ON COLUMN usm_credentials.auth_method IS 'SNMP v3 USM authentication method';
COMMENT ON COLUMN usm_credentials.priv_method IS 'SNMP v3 USM encryption method';
COMMENT ON COLUMN usm_credentials.auth_password IS 'SNMP v3 USM authentication password';
COMMENT ON COLUMN usm_credentials.priv_password IS 'SNMP v3 USM encryption password';
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
  filter clob null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE network_maps IS '';
COMMENT ON COLUMN network_maps.id IS '';
COMMENT ON COLUMN network_maps.map_type IS '';
COMMENT ON COLUMN network_maps.layout IS '';
COMMENT ON COLUMN network_maps.seed IS '';
COMMENT ON COLUMN network_maps.radius IS '';
COMMENT ON COLUMN network_maps.background IS '';
COMMENT ON COLUMN network_maps.bg_latitude IS '';
COMMENT ON COLUMN network_maps.bg_longitude IS '';
COMMENT ON COLUMN network_maps.bg_zoom IS '';
COMMENT ON COLUMN network_maps.flags IS '';
COMMENT ON COLUMN network_maps.bg_color IS '';
COMMENT ON COLUMN network_maps.link_color IS '';
COMMENT ON COLUMN network_maps.link_routing IS '';
COMMENT ON COLUMN network_maps.object_display_mode IS '';
COMMENT ON COLUMN network_maps.filter IS '';
CREATE TABLE network_map_elements
(
  map_id integer not null,
  element_id integer not null,
  element_type integer not null,
  element_data clob not null,
  flags integer not null,
  PRIMARY KEY(map_id,element_id)
) ;
COMMENT ON TABLE network_map_elements IS '';
COMMENT ON COLUMN network_map_elements.map_id IS '';
COMMENT ON COLUMN network_map_elements.element_id IS '';
COMMENT ON COLUMN network_map_elements.element_type IS '';
COMMENT ON COLUMN network_map_elements.element_data IS '';
COMMENT ON COLUMN network_map_elements.flags IS '';
CREATE TABLE network_map_links
(
  map_id integer not null,
  element1 integer not null,
  element2 integer not null,
  link_type integer not null,
  link_name varchar(255) null,
  connector_name1 varchar(255) null,
  connector_name2 varchar(255) null,
  element_data clob null,
  flags integer not null
) ;
CREATE INDEX idx_network_map_links_map_id ON network_map_links(map_id);
COMMENT ON TABLE network_map_links IS '';
COMMENT ON COLUMN network_map_links.map_id IS '';
COMMENT ON COLUMN network_map_links.element1 IS '';
COMMENT ON COLUMN network_map_links.element2 IS '';
COMMENT ON COLUMN network_map_links.link_type IS '';
COMMENT ON COLUMN network_map_links.link_name IS '';
COMMENT ON COLUMN network_map_links.connector_name1 IS '';
COMMENT ON COLUMN network_map_links.connector_name2 IS '';
COMMENT ON COLUMN network_map_links.element_data IS '';
COMMENT ON COLUMN network_map_links.flags IS '';
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
COMMENT ON TABLE images IS '';
COMMENT ON COLUMN images.guid IS '';
COMMENT ON COLUMN images.name IS '';
COMMENT ON COLUMN images.category IS '';
COMMENT ON COLUMN images.mimetype IS '';
COMMENT ON COLUMN images.protected IS '';
CREATE TABLE dashboards
(
  id integer not null,
  num_columns integer not null,
  options integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE dashboards IS '';
COMMENT ON COLUMN dashboards.id IS '';
COMMENT ON COLUMN dashboards.num_columns IS '';
COMMENT ON COLUMN dashboards.options IS '';
CREATE TABLE dashboard_elements
(
  dashboard_id integer not null,
  element_id integer not null,
  element_type integer not null,
  element_data clob null,
  layout_data clob null,
  PRIMARY KEY(dashboard_id,element_id)
) ;
COMMENT ON TABLE dashboard_elements IS '';
COMMENT ON COLUMN dashboard_elements.dashboard_id IS '';
COMMENT ON COLUMN dashboard_elements.element_id IS '';
COMMENT ON COLUMN dashboard_elements.element_type IS '';
COMMENT ON COLUMN dashboard_elements.element_data IS '';
COMMENT ON COLUMN dashboard_elements.layout_data IS '';
CREATE TABLE dashboard_associations
(
  object_id integer not null,
  dashboard_id integer not null,
  PRIMARY KEY(object_id,dashboard_id)
) ;
COMMENT ON TABLE dashboard_associations IS '';
COMMENT ON COLUMN dashboard_associations.object_id IS '';
COMMENT ON COLUMN dashboard_associations.dashboard_id IS '';
CREATE TABLE business_services
(
  service_id integer not null,
  PRIMARY KEY(service_id)
) ;
COMMENT ON TABLE business_services IS '';
COMMENT ON COLUMN business_services.service_id IS '';
CREATE TABLE slm_checks
(
  id integer not null,
  type integer not null,
  content clob null,
  threshold_id integer not null,
  reason varchar(255) null,
  is_template integer not null,
  template_id integer not null,
  current_ticket integer not null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE slm_checks IS '';
COMMENT ON COLUMN slm_checks.id IS '';
COMMENT ON COLUMN slm_checks.type IS '';
COMMENT ON COLUMN slm_checks.content IS '';
COMMENT ON COLUMN slm_checks.threshold_id IS '';
COMMENT ON COLUMN slm_checks.reason IS '';
COMMENT ON COLUMN slm_checks.is_template IS '';
COMMENT ON COLUMN slm_checks.template_id IS '';
COMMENT ON COLUMN slm_checks.current_ticket IS '';
CREATE TABLE node_links
(
  nodelink_id integer not null,
  node_id integer not null,
  PRIMARY KEY(nodelink_id)
) ;
COMMENT ON TABLE node_links IS '';
COMMENT ON COLUMN node_links.nodelink_id IS '';
COMMENT ON COLUMN node_links.node_id IS '';
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
COMMENT ON TABLE slm_agreements IS '';
COMMENT ON COLUMN slm_agreements.agreement_id IS '';
COMMENT ON COLUMN slm_agreements.service_id IS '';
COMMENT ON COLUMN slm_agreements.org_id IS '';
COMMENT ON COLUMN slm_agreements.uptime IS '';
COMMENT ON COLUMN slm_agreements.period IS '';
COMMENT ON COLUMN slm_agreements.start_date IS '';
COMMENT ON COLUMN slm_agreements.notes IS '';
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
COMMENT ON TABLE slm_tickets IS '';
COMMENT ON COLUMN slm_tickets.ticket_id IS '';
COMMENT ON COLUMN slm_tickets.service_id IS '';
COMMENT ON COLUMN slm_tickets.check_id IS '';
COMMENT ON COLUMN slm_tickets.create_timestamp IS '';
COMMENT ON COLUMN slm_tickets.close_timestamp IS '';
COMMENT ON COLUMN slm_tickets.reason IS '';
CREATE TABLE slm_service_history
(
  record_id integer not null,
  service_id integer not null,
  change_timestamp integer not null,
  new_status integer not null,
  PRIMARY KEY(record_id)
) ;
COMMENT ON TABLE slm_service_history IS '';
COMMENT ON COLUMN slm_service_history.record_id IS '';
COMMENT ON COLUMN slm_service_history.service_id IS '';
COMMENT ON COLUMN slm_service_history.change_timestamp IS '';
COMMENT ON COLUMN slm_service_history.new_status IS '';
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
COMMENT ON TABLE organizations IS '';
COMMENT ON COLUMN organizations.id IS '';
COMMENT ON COLUMN organizations.parent_id IS '';
COMMENT ON COLUMN organizations.org_type IS '';
COMMENT ON COLUMN organizations.name IS '';
COMMENT ON COLUMN organizations.description IS '';
COMMENT ON COLUMN organizations.manager IS '';
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
COMMENT ON TABLE persons IS '';
COMMENT ON COLUMN persons.id IS '';
COMMENT ON COLUMN persons.org_id IS '';
COMMENT ON COLUMN persons.first_name IS '';
COMMENT ON COLUMN persons.last_name IS '';
COMMENT ON COLUMN persons.title IS '';
COMMENT ON COLUMN persons.status IS '';
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
COMMENT ON TABLE job_history IS '';
COMMENT ON COLUMN job_history.id IS '';
COMMENT ON COLUMN job_history.time_created IS '';
COMMENT ON COLUMN job_history.time_started IS '';
COMMENT ON COLUMN job_history.time_finished IS '';
COMMENT ON COLUMN job_history.job_type IS '';
COMMENT ON COLUMN job_history.description IS '';
COMMENT ON COLUMN job_history.additional_info IS '';
COMMENT ON COLUMN job_history.node_id IS '';
COMMENT ON COLUMN job_history.user_id IS '';
COMMENT ON COLUMN job_history.status IS '';
COMMENT ON COLUMN job_history.failure_message IS '';
CREATE TABLE licenses
(
  id integer not null,
  content clob null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE licenses IS '';
COMMENT ON COLUMN licenses.id IS '';
COMMENT ON COLUMN licenses.content IS '';
CREATE TABLE mapping_tables
(
  id integer not null,
  name varchar(63) not null,
  flags integer not null,
  description varchar(4000) null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE mapping_tables IS '';
COMMENT ON COLUMN mapping_tables.id IS '';
COMMENT ON COLUMN mapping_tables.name IS '';
COMMENT ON COLUMN mapping_tables.flags IS '';
COMMENT ON COLUMN mapping_tables.description IS '';
CREATE TABLE mapping_data
(
  table_id integer not null,
  md_key varchar(63) not null,
  md_value varchar(255) null,
  description varchar(4000) null,
  PRIMARY KEY(table_id,md_key)
) ;
COMMENT ON TABLE mapping_data IS '';
COMMENT ON COLUMN mapping_data.table_id IS '';
COMMENT ON COLUMN mapping_data.md_key IS '';
COMMENT ON COLUMN mapping_data.md_value IS '';
COMMENT ON COLUMN mapping_data.description IS '';
CREATE TABLE dci_summary_tables
(
  id integer not null,
  guid varchar(36) not null,
  menu_path varchar(255) null,
  title varchar(127) null,
  node_filter clob null,
  flags integer not null,
  columns clob null,
  PRIMARY KEY(id)
) ;
COMMENT ON TABLE dci_summary_tables IS '';
COMMENT ON COLUMN dci_summary_tables.id IS '';
COMMENT ON COLUMN dci_summary_tables.guid IS '';
COMMENT ON COLUMN dci_summary_tables.menu_path IS '';
COMMENT ON COLUMN dci_summary_tables.title IS '';
COMMENT ON COLUMN dci_summary_tables.node_filter IS '';
COMMENT ON COLUMN dci_summary_tables.flags IS '';
COMMENT ON COLUMN dci_summary_tables.columns IS '';
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
COMMENT ON TABLE scheduled_tasks IS '';
COMMENT ON COLUMN scheduled_tasks.id IS '';
COMMENT ON COLUMN scheduled_tasks.taskId IS '';
COMMENT ON COLUMN scheduled_tasks.schedule IS '';
COMMENT ON COLUMN scheduled_tasks.params IS '';
COMMENT ON COLUMN scheduled_tasks.execution_time IS '';
COMMENT ON COLUMN scheduled_tasks.last_execution_time IS '';
COMMENT ON COLUMN scheduled_tasks.flags IS '';
COMMENT ON COLUMN scheduled_tasks.owner IS '';
COMMENT ON COLUMN scheduled_tasks.object_id IS '';
CREATE TABLE zmq_subscription
(
  object_id integer not null,
  subscription_type char(1) not null,
  ignore_items integer not null,
  items clob,
  PRIMARY KEY(object_id, subscription_type)
) ;
COMMENT ON TABLE zmq_subscription IS '';
COMMENT ON COLUMN zmq_subscription.object_id IS '';
COMMENT ON COLUMN zmq_subscription.subscription_type IS '';
COMMENT ON COLUMN zmq_subscription.ignore_items IS '';
COMMENT ON COLUMN zmq_subscription.items IS '';
CREATE TABLE currency_codes
(
 numeric_code char(3) not null,
 alpha_code char(3) not null,
 description varchar(127) not null,
 exponent integer not null,
 PRIMARY KEY(numeric_code)
) ;
COMMENT ON TABLE currency_codes IS 'List of currency codes';
COMMENT ON COLUMN currency_codes.numeric_code IS 'Numeric ISO code';
COMMENT ON COLUMN currency_codes.alpha_code IS 'Alphabetical ISO code';
COMMENT ON COLUMN currency_codes.description IS 'Description';
COMMENT ON COLUMN currency_codes.exponent IS 'Exponent for minor units';
CREATE TABLE country_codes
(
 numeric_code char(3) not null,
 alpha_code char(2) not null,
 alpha3_code char(3) not null,
 name varchar(127) not null,
 PRIMARY KEY(numeric_code)
) ;
COMMENT ON TABLE country_codes IS 'List of country codes';
COMMENT ON COLUMN country_codes.numeric_code IS 'Numeric ISO code';
COMMENT ON COLUMN country_codes.alpha_code IS 'Alphabetical 2 character ISO code';
COMMENT ON COLUMN country_codes.alpha3_code IS 'Alphabetical 3 character ISO code';
COMMENT ON COLUMN country_codes.name IS 'Country name';
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
 VALUES ('Syntax','ORACLE');
INSERT INTO metadata (var_name,var_value)
 VALUES ('IDataTableCreationCommand','CREATE TABLE idata_%d (item_id integer not null,idata_timestamp integer not null,idata_value varchar(255) null)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('IDataIndexCreationCommand_0','CREATE INDEX idx_idata_%d_id_timestamp ON idata_%d(item_id,idata_timestamp DESC)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('TDataTableCreationCommand_0','CREATE TABLE tdata_%d (item_id integer not null,tdata_timestamp integer not null,tdata_value ' || 'clob' || ' null)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('TDataIndexCreationCommand_0','CREATE INDEX idx_tdata_%d ON tdata_%d(item_id,tdata_timestamp)');
INSERT INTO metadata (var_name,var_value)
 VALUES ('LocationHistory','CREATE TABLE gps_history_%d (latitude varchar(20), longitude varchar(20), accuracy integer not null, start_timestamp integer not null, end_timestamp integer not null, PRIMARY KEY(start_timestamp))');
