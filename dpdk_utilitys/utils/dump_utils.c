void hexdump(u_int16_t *buf, int size){
  int i;
  for (i = 0;i < size; i++){
    fprintf(stdout, "%04x ", *(buf + i));
    if ((i + 1) % 8 == 0){ 
      fprintf(stdout, "\n");
    }   
  }
  fprintf(stdout, "\nfin\n");
}

void print_mbuf(const struct rte_mbuf *bufs){
  printf("-----print_mbuf-----\n");

  printf("data_off: %u\n", bufs->data_off);
  printf("refcnt: %u\n", bufs->refcnt);
  printf("nb_segs: %u\n", bufs->nb_segs);
  printf("port: %u\n", bufs->port);
  printf("ol_flags: %u\n", bufs->ol_flags);
  printf("packet_type: %u\n", bufs->packet_type);
  printf("pkt_len: %u\n", bufs->pkt_len);
  printf("data_len: %u\n", bufs->data_len);
  printf("vlan_tci: %u\n", bufs->vlan_tci);
  printf("rss: %u\n", bufs->hash.rss);
  printf("vlan_tci_outer: %u\n", bufs->vlan_tci_outer);
  printf("buf_len: %u\n", bufs->buf_len);
  printf("timestamp: %u\n", bufs->timestamp);
  printf("udata: %u\n", bufs->udata64);
  printf("tx_offlead: %u\n", bufs->tx_offload);
  printf("priv_size: %u\n", bufs->priv_size);
  printf("timesync: %u\n", bufs->timesync);
  printf("seqn: %u\n", bufs->seqn);

  printf("--------------------\n");
}
