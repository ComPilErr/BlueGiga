char outbuf[128];
char *cmd = "SET CONTROL MUX 0";
int link = 0xff, pos = 0;
int len = strlen(cmd);
bool f = true;

void setup() {
  Serial.begin(115200);

  outbuf[pos++]=0xbf;
  outbuf[pos++]=link;
  outbuf[pos++]=0;
  outbuf[pos++]=len;
  memmove(outbuf+pos, cmd, len);
  pos+=len;
  outbuf[pos++]=link^0xff;
}

void loop() {
  if (f)
  {
    for ( int i=0; i<len; i++)
    {
      Serial.write(outbuf[i]);
      }
    f = false;
    }
  }
