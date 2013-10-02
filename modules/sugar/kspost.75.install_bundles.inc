mkdir -p /home/olpc/{Activities,Library}
chown olpc:olpc /home/olpc/{Activities,Library}

shopt -s nullglob
for i in /build_shared/sugar-bundles/*; do
	echo "START installing $i"
	if [ "${i:(-4)}" == ".xol" ]; then
		/usr/bin/unzip -d /home/olpc/Library -q $i > /dev/null
	else
		/bin/su -c "/usr/bin/sugar-install-bundle $i" - olpc > /dev/null
	fi
	echo "END installed $i complete"
done
shopt -u nullglob

chown -R olpc:olpc /home/olpc/{Activities,Library}
