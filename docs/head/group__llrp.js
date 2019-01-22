var group__llrp =
[
    [ "LlrpRdmMessage", "struct_llrp_rdm_message.html", [
      [ "msg", "struct_llrp_rdm_message.html#a8b5ccb6be7a1562c3c083ce2f4fabbed", null ],
      [ "source_cid", "struct_llrp_rdm_message.html#a4336333456f3fbffa1d9439d168dde75", null ],
      [ "transaction_num", "struct_llrp_rdm_message.html#a30148765da319f02b0b87b37af7aa04a", null ]
    ] ],
    [ "LlrpTarget", "struct_llrp_target.html", [
      [ "component_type", "struct_llrp_target.html#a98b74ef88251de997b90bb399762371a", null ],
      [ "hardware_address", "struct_llrp_target.html#a24955a85fa1bd4c308bad2de133999e2", null ],
      [ "target_cid", "struct_llrp_target.html#ac8086ccee96a4ab8223e50274698778e", null ],
      [ "target_uid", "struct_llrp_target.html#a75f90bc874d3d8df583a0d01b7453327", null ]
    ] ],
    [ "LlrpData", "struct_llrp_data.html", [
      [ "contents", "struct_llrp_data.html#a8e36d515f75a443eb5fa30e53545ec84", null ],
      [ "discovered_target", "struct_llrp_data.html#a321aa53e12177e83a30f4e06d4083bff", null ],
      [ "rdm", "struct_llrp_data.html#a5a35901a0014bc60ebca393d54bd525d", null ],
      [ "type", "struct_llrp_data.html#ab7fcc0446ab736487ba09e280c40063e", null ]
    ] ],
    [ "LlrpPoll", "struct_llrp_poll.html", [
      [ "data", "struct_llrp_poll.html#ac48d58e1365f281d53913056a6fe2b2e", null ],
      [ "err", "struct_llrp_poll.html#a2d84f39897e3cbaf81be57d00dce398b", null ],
      [ "handle", "struct_llrp_poll.html#ad43da949d0860c5abbf00568f0c3f183", null ]
    ] ],
    [ "LLRP_SOCKET_INVALID", "group__llrp.html#ga2baa8fb9aa3e8ea94551e1317d253923", null ],
    [ "llrp_socket_t", "group__llrp.html#ga4b0e9d9266de72e17f7d3e2cc67934bb", null ],
    [ "LlrpData", "group__llrp.html#ga94303e958d4a25e39b2445efa6e8183b", null ],
    [ "LlrpPoll", "group__llrp.html#ga74dc86fbedf8ff761f4299ace223dc06", null ],
    [ "LlrpRdmMessage", "group__llrp.html#ga0684ce797f8efce9c75f32425f23ba0b", null ],
    [ "LlrpTarget", "group__llrp.html#gacf8fdde5da4def7444ee4b5852c92598", null ],
    [ "llrp_component_t", "group__llrp.html#ga994bb762a1d4572348671a0b1e73d567", [
      [ "kLLRPCompRPTDevice", "group__llrp.html#gga994bb762a1d4572348671a0b1e73d567a27701735ea730e38bdf34f3c1dad5e5c", null ],
      [ "kLLRPCompRPTController", "group__llrp.html#gga994bb762a1d4572348671a0b1e73d567aad61b176a100ef6111211c8850ee9773", null ],
      [ "kLLRPCompBroker", "group__llrp.html#gga994bb762a1d4572348671a0b1e73d567aa83bf54814e6f7c0153c3e26919e8ebe", null ],
      [ "kLLRPCompUnknown", "group__llrp.html#gga994bb762a1d4572348671a0b1e73d567abbd7bd4e03c1775537d37828bc799a95", null ]
    ] ],
    [ "llrp_data_t", "group__llrp.html#ga5208454a836436852d2adcb8cee3908b", [
      [ "kLLRPNoData", "group__llrp.html#gga5208454a836436852d2adcb8cee3908ba77e06ae045f858ea8d334cdc56bed16c", null ],
      [ "kLLRPDataRDM", "group__llrp.html#gga5208454a836436852d2adcb8cee3908ba84ff4dd9f7ad94e2bfac218bf9624dd4", null ],
      [ "kLLRPDataDiscoveredTarget", "group__llrp.html#gga5208454a836436852d2adcb8cee3908ba896becc45dc32c1b6c233a05dad4e60c", null ],
      [ "kLLRPDataDiscoveryFinished", "group__llrp.html#gga5208454a836436852d2adcb8cee3908baf908f9c2ba6c2d2d2dd61280e8212f17", null ]
    ] ],
    [ "llrp_close_socket", "group__llrp.html#ga6fd3da28e9f360318d50ff288d33f5d0", null ],
    [ "llrp_create_manager_socket", "group__llrp.html#ga6584b20577dca00b9cbdab334e8213b2", null ],
    [ "llrp_create_target_socket", "group__llrp.html#ga29eb0293812c3c1999a6329924ca8bf7", null ],
    [ "llrp_deinit", "group__llrp.html#ga6f14056c4e9e19d7f6a4de7402aa1f00", null ],
    [ "llrp_init", "group__llrp.html#ga469b1401cfd75803bd8231450daf5493", null ],
    [ "llrp_send_rdm_command", "group__llrp.html#ga80955dd18e994ea955ed8d4e11bff0be", null ],
    [ "llrp_send_rdm_response", "group__llrp.html#ga8780073840d8db36385b3824e7e922d1", null ],
    [ "llrp_start_discovery", "group__llrp.html#ga811169054cb1bb2fd201169f80cc8517", null ],
    [ "llrp_stop_discovery", "group__llrp.html#gac423075fed98430e7b3140432f812942", null ],
    [ "llrp_target_update_connection_state", "group__llrp.html#gaa2c6b08bd754bd10da37dbc853a23cbc", null ],
    [ "llrp_update", "group__llrp.html#ga70da0c87d56a71ec05bb1be9669ab0eb", null ]
];